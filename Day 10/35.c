#include<stdio.h>
int main(){
    int rows=5,i,j,k;
    for(i=1;i<=rows;i++){
        for(j=1;j<=rows;j++){
            printf(" ");
        }
        for(k=1;k<=(2*i-1); k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}