#include<stdio.h>
int sum(int num1,int num2);
int main(){
    int result,a,b;
    printf("enter the two numbers:");
    scanf("%d%d",&a,&b);
    result=sum(a,b);
    printf("%d",result);
    return 0;
}

int sum(int num1,int num2)
{
    return num1 + num2;
}