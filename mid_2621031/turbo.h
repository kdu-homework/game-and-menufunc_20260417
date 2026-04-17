#ifndef TURBOC_HEADER
#define TURBOC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);
void textcolor(int);

#define delay(n) Sleep(n)
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#ifndef TURBOC_PROTOTYPE_ONLY

void clrscr()
{
     system("cls");
}

void cls()
{
   system("cls");
}

void settextcolor(int color, int bgcolor)
{
   color &= 0xf;
   bgcolor &= 0xf;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(bgcolor<<4|color));
}

void setColor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

/*
0 - 검정색
1 - 파랑색
2 - 초록색
3 - 옥색
4 - 빨간색
5 - 자주색
6 - 노랑색
7 - 흰색
8 - 회색
9 - 연한 파랑색
A - 연한 초록색
B - 연한 옥색
C - 연한 빨간색
D - 연한 자주색
E - 연한 노랑색
F - 밝은 흰색

[밝은 흰색]의 음영색을 가진 [빨간색]의 글자를 출력 :0x00F4 
*/ 

void gotoxy(int x, int y)
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

int wherex()
{
     CONSOLE_SCREEN_BUFFER_INFO BufInfo;
     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
     return BufInfo.dwCursorPosition.X;
}

int wherey()
{
     CONSOLE_SCREEN_BUFFER_INFO BufInfo;
     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
     return BufInfo.dwCursorPosition.Y;
}

void setcursortype(CURSOR_TYPE c)
{
     CONSOLE_CURSOR_INFO CurInfo;
     switch (c) {
     case NOCURSOR:
          CurInfo.dwSize=1;
          CurInfo.bVisible=FALSE;
          break;
     case SOLIDCURSOR:
          CurInfo.dwSize=100;
          CurInfo.bVisible=TRUE;
          break;
     case NORMALCURSOR:
          CurInfo.dwSize=20;
          CurInfo.bVisible=TRUE;
          break;
     }
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}

#endif // TURBOC_PROTOTYPE_ONLY
#endif // TURBOC_HEADER