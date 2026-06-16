#include<stdio.h>
#include <stdbool.h>
bool isprime(int n);
int main(){
    int num;
    printf("enter the positive number:");
   if (scanf("%d",&num)!=1){
    printf("invalide input.\n");
    return 1;
   }
   if(isprime(num)){
    printf("%d is a prime number.\n", num);
   }else{ 
    printf("%d is not a prime number.\n", num);
   }
   return 0;
}
    bool isprime(int n){
        if(n<= 1){
            return true;
        }
        if(n%2==0){
            return false;
        }
        
    }