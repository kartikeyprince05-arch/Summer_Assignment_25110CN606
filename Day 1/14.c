#include<stdio.h>
int main()
{
    int count=0,n;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n>10)
    {
        n/=10;
        count++;
    }
    printf("The number of digits in the given number is: %d",count+1);
    return 0;
}