#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "turbo.h"

#define WIDTH 61
#define HEIGHT 11

int packman_x = 1;
int packman_y = 1;
int packman_eat = 0;

char name[20] = "";
int score = 0;
char id[7] = "";
int data_check = 0;

int maze[HEIGHT][WIDTH] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,0,0,1,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,3,1,0,0,0,1,0,3,0,0,1},
	{1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,3,0,1,0,0,0,1,3,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,3,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1},
	{1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,3,1,0,0,0,1,3,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,1,1,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1},
	{1,3,1,0,1,0,0,3,1,0,1,0,0,0,3,0,1,0,0,0,1,3,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,3,0,1,1},
	{1,0,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,3,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

//== 데이터 입력 함수 ==
void set_data() {
	gotoxy(25, 4);
	scanf("%s", name);
	
	gotoxy(25, 5);
	scanf("%d", &score);

	gotoxy(25, 6);
	scanf("%s", id);
	
	data_check = 1;

}

void put_data() {
	if (!data_check) {
		gotoxy(25, 4);
		printf("No Data");
		gotoxy(25, 5);
		printf("No Data");
		gotoxy(25, 6);
		printf("No Data");
		return;
	}
	gotoxy(25, 4);
	printf("%s", name);
	gotoxy(25, 5);
	printf("%d", score);
	gotoxy(25, 6);
	printf("%s", id);
}

// == 인터페이스 함수 ==
void draw_box() {
	//┌ ┬ ─ ┬ ┐
	printf("\u250C");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u252C");
			continue;
		}
		printf("\u2500");
	}
	printf("\u2510\n");

	//│ │    │ │
	printf("\u2502");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u2502");
			continue;
		}
		printf(" ");
	}
	printf("\u2502\n");

	//├ ┼ ─ ┼ ┤
	printf("\u251C");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u253C");
			continue;
		}
		printf("\u2500");
	}
	printf("\u2524\n");

	//│ │    │ │
	//│ │    │ │
	//│ │    │ │
	for (int i = 0; i < 6; i++) {
		printf("\u2502");
		for (int k = 0; k < 58; k++) {
			if (k == 6 || k == 50) {
				printf("\u2502");
				continue;
			}
			printf(" ");
		}
		printf("\u2502\n");
	}

	//├ ┼ ─ ┼ ┤
	printf("\u251C");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u253C");
			continue;
		}
		printf("\u2500");
	}
	printf("\u2524\n");


	//│ │    │ │
	printf("\u2502");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u2502");
			continue;
		}
		printf(" ");
	}
	printf("\u2502\n");

	//└ ┴ ─ ┴ ┘
	printf("\u2514");
	for (int i = 0; i < 58; i++) {
		if (i == 6 || i == 50) {
			printf("\u2534");
			continue;
		}
		printf("\u2500");
	}
	printf("\u2518\n");
}

void draw_main() {
	draw_box();

	gotoxy(25, 1);
	printf("Main Menu");

	gotoxy(22, 4);
	printf("1. Data Input");

	gotoxy(22, 5);
	printf("2. Data Output");

	gotoxy(22, 6);
	printf("3. Game");

	gotoxy(22, 7);
	printf("4. Exit");

	gotoxy(20, 10);
	printf("Select Menu [     ]");
}

void draw_input() {
	draw_box();

	gotoxy(25, 1);
	printf("Data Input");

	gotoxy(15, 4);
	printf("Name  :");

	gotoxy(15, 5);
	printf("Score :");

	gotoxy(15, 6);
	printf("ID    :");

	gotoxy(13, 10);
	printf("Press [Enter] key to Main Menu");


}

void draw_output() {
	draw_box();

	gotoxy(24, 1);
	printf("Data Output");

	gotoxy(15, 4);
	printf("Name  : ");

	gotoxy(15, 5);
	printf("Score : ");

	gotoxy(15, 6);
	printf("ID    : ");

	gotoxy(13, 10);
	printf("Press [Enter] key to Main Menu");
}

void draw_exit() {
	draw_box();

	gotoxy(27, 1);
	printf("Exit");

	gotoxy(24, 6);
	printf("Bye.......");

	gotoxy(13, 10);
	printf("Press [Enter] key to Main Menu");

}

// == 게임 함수 ==
void show_maze() {

	clrscr();
	gotoxy(0, 0);

	for (int y = 0; y < HEIGHT - 1; y++) {
		for (int x = 0; x < WIDTH - 1; x++) {
			if (maze[y][x] == 0) printf(" ");
			else if (maze[y][x] == 1) printf("\u2592");
			else if (maze[y][x] == 3) printf("*");
		}
		printf("\n");
	}

	gotoxy(packman_x, packman_y);
	printf("@");  //print packman on start position
	gotoxy(0, 14);
	printf("Your Score: %d", packman_eat);
	gotoxy(0, 15);
	printf("Packman Position [ %2d, %2d ]", packman_x, packman_y);
	gotoxy(0, 16);
	printf("Press [ESC] to exit game...");
}

void game_move(int x, int y) {
	int nx = packman_x + x;
	int ny = packman_y + y;

	if (maze[ny][nx] == 1) return;

	gotoxy(packman_x, packman_y);
	printf(" ");

	packman_x = nx;
	packman_y = ny;

	if (maze[packman_y][packman_x] == 3) {
		packman_eat++;
		maze[packman_y][packman_x] = 0;
	}

	gotoxy(packman_x, packman_y);
	printf("@");
}

void game() {
	char c = 0;

	while (c != 27) {

		if (_kbhit()) {
			c = _getch();

			if (c == 224 || c == 0 || c == -32) {
				c = _getch();

				switch (c) {
				case 72:  //up
					if (packman_y > 1) game_move(0, -1);
					break;

				case 80:  //down
					if (packman_y < HEIGHT - 2) game_move(0, 1);
					break;

				case 75:  //left
					if (packman_x > 1) game_move(-1, 0);
					break;

				case 77:  //right
					if (packman_x < WIDTH - 2) game_move(1, 0);
					break;
				}

				gotoxy(0, 14);
				printf("Your Score: %d", packman_eat);
				gotoxy(0, 15);
				printf("Packman Position [ %2d, %2d ]", packman_x, packman_y);
			}
		}
	}
}
void run_game() {
	show_maze();
	game();
	clrscr();
	draw_main();
	gotoxy(35, 10);
}

int main() {
	int menu;
	char anykey;

	while (1) {
		draw_main();

		gotoxy(35, 10);
		scanf("%d", &menu);
		clrscr();

		switch (menu) {
		case 1:draw_input(); set_data();break;

		case 2:draw_output(); put_data(); break;

		case 3:run_game(); break;

		case 4:draw_exit(); break;
		}

		// ENTER키 입력 받기
		getchar();
		scanf("%c", &anykey);
		clrscr();

		if (menu == 4) break;
	}
	return 0;
}



