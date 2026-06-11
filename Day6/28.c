#include<stdio.h>
int main()
{ 
    long long binary;
    int decimal=0,base=1,reminder;
    printf("enter a binary number");
    scanf("%lld",&binary);
    long long temp=binary;
    while(binary>0){
        reminder=binary%10;
        decimal+=reminder*base;
        binary/=10;
        base*=2;
    }
    printf("binary:%lld",binary);
    printf("decimal:%d\n", decimal);
    return 0;
}