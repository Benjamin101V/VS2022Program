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
		printf("�㻹��%d�λ���\n",count);
		printf("��������������>");
		scanf("%d", &guess);

		if (guess < r) {
			printf("��С��\n");
		}
		else if (guess > r) {
			printf("�´���\n");
		}
		else {
			printf("��ϲ���¶��ˣ���Ϊ%d\n",r);
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

		printf("��ѡ��>");
		scanf("%d", &input);

		switch (input) {

		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
		}

	} while (input);

	return 0;
}