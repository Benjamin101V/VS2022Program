#include<stdio.h>

//简单函数调用

int add(int a,int b)
{
  return a+b;      //加法函数
}

int main()
{
  int a=add(3,3);
  printf("%d",a);

  return 0;
}
