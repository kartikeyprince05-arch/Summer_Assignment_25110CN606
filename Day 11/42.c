#include<stdio.h>
long long findfactorial(int n){
    long long fact = 1;
    for(int i=1;i<=n;i++){
        fact *= i;
    }
    return fact;
}
int main(){
    int num;
    printf("enter the number :");
    scanf("#d",&num);
    if(num<0){
        printf("factorial is not defined for negative numbers.\n");
    }else{
        printf("factorial of %d=%lld\n", num , findfactorial(num));
    }
    return 0;
}