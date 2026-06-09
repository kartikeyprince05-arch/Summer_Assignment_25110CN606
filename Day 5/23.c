#include<stdio.h>
int main()
{
    int num,sum=0,temp,t;
    printf("Enter a number:");
    scanf("%d",&num);
    temp=num;
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)
        sum+=i;
    }
    printf("The sum of divisors of  %d is %d", num, sum);
    if(sum==temp)
    printf("\n%d is a perfect number", num);
    else
    printf("\n%d is not a perfect number", num);
    return 0;


}