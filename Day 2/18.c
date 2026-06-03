#include<stdio.h>
int main()
{ 
int i,d,rev=0,n,temp;
printf("Enter the value of n:");
scanf("%d",&n);
temp=n;
while(n>0)
{
    d=n%10;
    rev=rev*10+d;
    n=n/10;
}
if(temp==rev)
{
    printf("The given number is a palindrome");
}
else
{
    printf("The given number is not a palindrome");
}
return 0;
}