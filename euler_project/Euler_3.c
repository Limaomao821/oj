/*
Euler project 3
这道题带来的最大启发是：超大型数组该怎么申请，还是压根不申请用别的方法
具体到此题，你想要素数筛，但是素数筛需要的记录状态的数组，根本申请不起，得4TB多内存

我不太明白，我现在用的这种方法，为什么可以这么快？？？
好吧，好像780000万次左右的除法并不是很耗时，我还以为会花点功夫
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int num){
    long long int i=2;
    long long upper_bound=sqrt(num);
    for(i=2;i<=upper_bound;++i){
        if(num%i==0) return 0;
    }

    return 1;
}

int main(void){
    long long int target = 600851475143;
    int sqrt_target = sqrt(target);
    sqrt_target += 1;

    int i=0;
    int biggest=1;
    for(i=2;i<=sqrt_target;++i){
        if(target%i==0){
            int temp = target / i;
            if(isPrime(i)){
                biggest = i;
            }
            if(isPrime(temp)){
                biggest = temp;
            }
        }
    }

    printf("%d", biggest);
}