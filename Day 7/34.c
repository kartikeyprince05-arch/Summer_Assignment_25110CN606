#include<stdio.h>
int reverse_recursive(int num, int reversed){
    if(num==0){
        return reversed;
    }
    int last_digit=num%10;
    reversed=reversed*10+last_digit;
    return reverse_recursive(num/10,reversed);
}
 int main(){
    int number;
    printf("enter a positive integer:");
    if(scanf("%d",&number)!=1){     
        printf("invalid input. Please enter a positive integer.\n");
        return 1;
    }
    int result=reverse_recursive(number,0);
    printf("reversed of %d is %d\n",number,result);
    return 0;
}
