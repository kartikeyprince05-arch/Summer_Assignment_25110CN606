#include<stdio.h>
int sumOfdigits(int num);
int main(){
    int number,result;
    printf("enter a positive integer:");
    scanf("%d",&number);
    if(number<0){
        number=-number;
    }
    result=sumOfdigits(number);
    printf("sum of digits of %d is %d\n",number,result);
    return 0;
}
int sumOfdigits(int num)
{
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumOfdigits(num / 10);
}