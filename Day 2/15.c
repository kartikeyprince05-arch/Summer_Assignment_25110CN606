#include<stdio.h>
int main()
{ 
int i,n,sum=0,d;
printf("Enter the value of n:");
scanf("%d",&n);
while(n>0)
{
    d=n%10;
    sum=sum+d;
    n=n/10;
}
printf("The sum of the digits in the given number is %d",sum);
return 0;


}