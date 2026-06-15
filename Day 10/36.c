#include<stdio.h>
int main(){
    int rows=5,i,j,k;
    for(i=0;i<rows;i++){
        for(j=0;j<i;j++){
            printf("");
        }
        for(k=0;k<(2*(rows-i)-1);k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}