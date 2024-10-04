#include <bits/stdc++.h>
#include "lib.cpp"
#include <conio.h> 
#include <thread>
#include <chrono>
using namespace std;


const int width = 30;
const int height = 10;
int x = 1; float y = height - 2;
bool isJumping = false;
int score = 0;
int obsX = width - 1, obsY = height -2;
bool isPressed = false;


void draw(){
	COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(i==y && j==x){
				cout<<"D";
			}
			else if(i==obsY && j==obsX){
				cout<<"O";
			}
			else {
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"Score: "<<score<<endl<<"Madebyoct1st68"<<endl;
}


void input(){
	if(_kbhit()){
		char key = _getch();
		if(key == ' ' && !isPressed){
			isJumping = true;
			isPressed = true;
		}
	}
}

void jumpL(){
	if(y < height - 2){
		y+=1;
	}
}


void logic(){
	if(isJumping && isPressed){
		isPressed = false;
		y-=3;
		if(y <= 0) y=0;
		isJumping = false;	
	}
	else {
		jumpL();
	}
	obsX-=2;
	if(obsX<0){
		score++;
		obsX = width - 1;
	}

	if(x == obsX && y == obsY){
		cout<<"Game over"<<endl;
		system("pause");
		exit(0);
	}
}

int main(){
	HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);


    while(true){
    	draw();
    	input();
    	logic();
    	//this_thread::sleep_for(chrono::milliseconds(100));
    	Sleep(150);
    }
    return 0;
}