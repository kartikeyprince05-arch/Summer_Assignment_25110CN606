#include<stdio.h>
int max(int a, int b);
int main(){
    int x,y,result;
    printf("enter the numbers:\n");
    scanf("%d%d",&x,&y);
    result=max(x,y);
    printf("the maximum number is : %d \n",result);
    return 0;
}
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }

    }