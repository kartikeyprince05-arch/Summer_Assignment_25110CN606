#include<stdio.h>
int main()
{
    int start,end,i,j,prime;
    printf("Enter the starting and ending numbers: ");
    scanf("%d %d", &start, &end);
    printf("Prime numbers between %d and %d are: ", start, end);    
    for(i=start; i<=end; i++)
    {
        prime=1;
        for(j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                prime=0;
                break;
            }
        }
        if(prime==1 && i>1)
            printf("%d ", i);
    }   
    return 0;
    
    








}