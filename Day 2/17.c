#include<stdio.h>
int main()
{
    int i,n,product=1;
    printf("Enter the value of n:");
    scanf("%d",&n);
    while(n>0)
    {
        int d=n%10;
        product=product*d;
        n=n/10;
    }
    printf("Product of digits is: %d",product); 
    return 0;



}