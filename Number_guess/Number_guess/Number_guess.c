#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void menu()
{
	printf("*********************\n");
	printf("****** 1. play ******\n");
	printf("****** 0. exit ******\n");
	printf("*********************\n");
}

void punishment()
{
	system("shutdown /s /t 60");
}

void game()
{
	int r = rand()%100+1;
	int guess = 0;
	int count = 5;

	while (count) {
		printf("你还有%d次机会\n",count);
		printf("请输入所猜数字>");
		scanf("%d", &guess);

		if (guess < r) {
			printf("猜小了\n");
		}
		else if (guess > r) {
			printf("猜大了\n");
		}
		else {
			printf("恭喜，猜对了，答案为%d\n",r);
			break;
		}
		count--;
	}
	if (count == 0) {
		printf("Game over!\n");

		punishment();
	}
	
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));

	do
	{
		menu();

		printf("请选择>");
		scanf("%d", &input);

		switch (input) {

		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}

	} while (input);

	return 0;
}