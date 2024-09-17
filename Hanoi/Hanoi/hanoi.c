#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int count = 0;

int hanoi(int n, char from, char to, char with)
{
	
	if (n == 1) {
		count++;
	}
	else {
		hanoi(n - 1, from, with, to);
		count++;
		hanoi(n - 1, with, to, with);
	}
	return count;
}

int main()
{
	int n;
	scanf("%d", &n);
	int r = hanoi(n, 'a', 'c', 'b');
	printf("%d", r);

	return 0;
}