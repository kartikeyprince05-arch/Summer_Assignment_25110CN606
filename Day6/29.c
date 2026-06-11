#include<stdio.h>
int countsetbits(unsigned int n)
{
    int count=0;
    while(n>0)
    {
        count+=n&1;
        n>>=1;
    }
    return count;

}
int main()
{
    unsigned int num;
    printf("enter a number:");
    scanf("%u",&num);
    int setbits=countsetbits(num);
    printf("number of set bits in %u is %d\n", num, setbits);
    return 0;
}