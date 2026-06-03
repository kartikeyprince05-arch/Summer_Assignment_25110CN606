#include<stdio.h>
int main()
{ 
    int i,n,revb=0,d;
    printf("Enter the value of n:");
    scanf("%d",&n);
    while(n>0)
    {
        d=n%10;
        revb=revb*10+d;
        n=n/10;
    }
    printf("The reverse of the given number is %d",revb);
    return 0;

}