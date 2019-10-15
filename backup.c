#include<stdio.h>
#include<stdlib.h>

typedef struct{
    _Bool landscape;
    _Bool tagged;
}block;

int main(void){
    printf("%ld\n", sizeof(block));
    printf("%ld\n", sizeof(int));
}