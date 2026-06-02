#include<stdio.h>
int main()
{
    int fact=1,n;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("The factorial of %d is: %d",n,fact);
    return 0;
}