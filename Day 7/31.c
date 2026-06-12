#include<stdio.h>
        unsigned long long factorial(int n);
        int main()
        {
            int num;
            printf("enter a positive integer:");
            if (scanf("%d",&num)!=1 || num<0){
                printf("invalid input. Please enter a positive integer.\n");
                return 1;
            }
            if(num<0){
                printf("factorial is not defined for negative numbers.\n");
                return 1;
            }
            else if(num>20)
            {
                printf("factorial result is too large to handle.\n");
                return 1;
            }
                else{
                    printf("factorial of %d is %llu\n", num, factorial(num));

                }
            return 0;
        }
        unsigned long long factorial(int n){
            if(n==0 || n==1){
                return 1;
            }
            else{
                return n*factorial(n-1);
            }
        }





