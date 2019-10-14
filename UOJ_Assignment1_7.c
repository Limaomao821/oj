#include<stdio.h>
#include<stdlib.h>

#define flag 1000000001

typedef struct{
    int count;
    int num;
}pair;

pair findMajority(int store[], int begin, int end){
    if(begin == end){
        pair temp;
        temp.count=1;temp.num=store[begin];
        return temp;
    }
    if((end-begin) == 1){
        if(store[begin] == store[end]){
            pair temp;
            temp.count=2;temp.num=store[begin];
            return temp;
        }else{
            pair temp;
            temp.count=0;temp.num=flag;
            return temp;
        }
    }
    
    int middle = (begin+end)/2;
    int element_num = end-begin+1;
    pair num1 = findMajority(store, begin, middle);
    pair num2 = findMajority(store, middle+1, end);
   
    pair temp;
    if(num1.num==num2.num){
        if(num1.num==flag){
            temp.num=flag;
            temp.count=0;
            return temp;
        }
        else{
            temp.count=num1.count+num2.count;
            temp.num=num1.num;
            return temp;
        }
    }else if(num1.num==flag){
        int i=begin;
        for(;i<=middle;++i){
            if(store[i]==num2.num) ++num2.count;
        }
        if(num2.count>element_num/2) return num2;
        else{
            temp.num=flag;
            temp.count=0;
            return temp;
        }
    }else if(num2.num==flag){
        int i=middle+1;
        for(;i<=end;++i){
            if(store[i]==num1.num) ++num1.count;
        }
        if(num1.count>element_num/2) return num1;
        else{
            temp.num=flag;
            temp.count=0;
            return temp;
        }
    }else{
        int i=begin;
        for(;i<=middle;++i){
            if(store[i]==num2.num) ++num2.count;
        }
        i=middle+1;
        for(;i<=end;++i){
            if(store[i]==num1.num) ++num1.count;
        }
        if(num2.count>element_num/2) return num2;
        else if(num1.count>element_num/2) return num1;
        else{
            temp.num=flag;
            temp.count=0;
            return temp;
        }
    }
}

int main(void){
    int num;
    scanf("%d", &num);

    int *array  = (int*)malloc(num*sizeof(int));

    int i=0;
    for(;i<num;++i){
        scanf("%d", array+i);
    }

    pair answer = findMajority(array, 0, num-1);

    printf("%d", answer.num);
    return 0;
}