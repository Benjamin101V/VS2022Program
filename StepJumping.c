#include<stdio.h>
#include<stdlib.h>

//跳台阶问题

int jump(int x)
{
    if(x==1){
        return 1;
    }
    else if(x==2){    //递归函数
        return 2;
    }
    else{
        return jump(x-1)+jump(x-2);
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int a=jump(n);
    printf("%d",a);

    return 0;
}
