#include<stdio.h>
int main()
{
    int start,end,n,i,d,armstrong=0,temp;
    printf("Enter the starting number:");
    scanf("%d",&start);
    printf("Enter the ending number:");
    scanf("%d",&end);
    printf("Armstrong numbers between %d and %d are:",start,end);
    for(n=start;n<=end;n++)
    {
        temp=n;
        armstrong=0;
        while(temp!=0)
        {
            d=temp%10;
            armstrong=armstrong+(d*d*d);
            temp=temp/10;
        }
        if(armstrong==n)
            printf("%d ",n);
    }
    return 0;




}