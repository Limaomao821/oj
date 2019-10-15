#include<stdio.h>
#include<stdlib.h>

int main(void){
    int m=1000, n=1000;
    printf("%d %d\n", m, n);
    int i=0, j=0;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            printf("1 ");
        }
        printf("\n");
    }
}