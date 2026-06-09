#include<stdio.h>
int main()
{
    long long num;
    printf("Enter a number:");
    scanf("%lld",&num);
    long long max_prime = -1;
    while (num % 2 == 0) {
        max_prime = 2;
        num /= 2;
    }
    for (long long i = 3; i <= num / 2; i += 2) {
        while (num % i == 0) {
            max_prime = i;
            num /= i;
        }
    }
    if (num > 2)
        max_prime = num;
    printf("The largest prime factor of the number is %lld", max_prime);
    return 0;





}