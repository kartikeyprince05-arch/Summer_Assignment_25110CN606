#include<stdio.h>
int main()
{  
    int n,i,d,armstrong=0,temp;
    printf("Enter the number:");
    scanf("%d",&n);
    temp=n;
    while(temp!=0)
    {
        d=temp%10;
        armstrong=armstrong+(d*d*d);
        temp=temp/10;
    }
    if(armstrong==n)
        printf("%d is an armstrong number",n);
    else
        printf("%d is not an armstrong number",n);
    return 0;



}