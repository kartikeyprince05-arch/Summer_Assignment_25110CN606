#include<stdio.h>
int main(){
    double base,exponent,result=1.0;
    printf("enter base:");
    scanf("%lf",&base);
    printf("enter exponent:");
    scanf("%lf",&exponent);
    if(exponent==0){
        result=1.0;
    }
    else if(exponent>0){
        for(int i=1;i<=exponent;i++){
            result*=base;
        }
    }
    else{
        for(int i=1;i<=-exponent;i++){
            result*=base;
        }
        result=1.0/result;
    }
    printf("%.2lf raised to the power of %.2lf is %.2lf\n", base, exponent, result);
    return 0;
}