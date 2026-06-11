#include<stdio.h>
int main()
{
    int decimal,i=0;
    int binary[32];
    printf("enter a decimal number");
    scanf("%d",&decimal);
    if (decimal==0){
        printf("binary: 0\n");
        return 0;


    }
while(decimal>0){
    binary[i] = decimal % 2;
    decimal = decimal / 2;
    i++;



}
    printf("binary:");
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);


    }
    printf("\n");

    }
    
