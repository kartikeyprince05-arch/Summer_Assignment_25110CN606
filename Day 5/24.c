#include<stdio.h>
int main()
{
    int num,originalnum,rem,sum=0;
    printf("Enter a number:");
    scanf("%d",&num);
    originalnum=num;
    while(num>0)
    {
        rem=num%10;
        int fact=1;
        for(int i=1;i<=rem;i++)
        {
            fact*=i;
        }
        sum+=fact;
        num/=10;
    }
    printf("The sum of the factorial of the digits of %d is %d", originalnum, sum);
    if(sum==originalnum)
    printf("\n%d is a strong number", originalnum);
    else
    printf("\n%d is not a strong number", originalnum);
    return 0;

}
