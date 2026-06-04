#include<stdio.h>
int main()
{
    int prime=1, n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            prime=0;
            break;
        }
    }
    if(prime==1 && n>1)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);
    return 0;




}
