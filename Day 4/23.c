#include<stdio.h>
int main()
{ 
    int febo,n,i;
    int a=0,b=1;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    printf("Fibonacci Series:");
    for(i=1;i<=n;i++)
    {
        printf("%d ",a);
        febo=a+b;
        a=b;
        b=febo;
    }
    return 0;




}