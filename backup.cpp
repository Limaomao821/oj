1 1 0 0 0 
0 1 0 0 1 
1 0 0 1 1 
0 0 0 0 0 
1 0 1 0 1

// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 100000
// int store[MAX];
// int cmp(const void*a,const void*b)
// {
//     return *(int*)a-*(int*)b;
// }
// int main(void)
// {
//     int num;
//     scanf("%d", &num);
    

//     int i=0;
//     for(;i<num;++i){
//         int temp;
//         scanf("%d", &temp);
//         store[i]=temp;
//     }
//     qsort(store,num,4,cmp);

//     printf("%d", store[(num-1)/2]);

//     // int possible_majority = -1;
//     // int continue_number = 1;
//     // for(i=1;i<num;++i){
//     //     if(store[i]==store[i-1]){
//     //         ++continue_number;
//     //         possible_majority = store[i];
//     //         if(continue_number > num/2){
//     //             printf("%d", possible_majority);
//     //             break;
//     //         }
//     //     }else{
//     //         continue_number = 1;
//     //         possible_majority = store[i];
//     //     }
//     // }
    
//     return 0;
// }

// #include <queue>
// #include <cstdio>
// using namespace std;

// int main(void)
// {
//     priority_queue<int> order;
//     int length, k;
//     scanf("%d%d", &length, &k);
//     for(int i=0; i<length; ++i){
//         int num;
//         scanf("%d", &num);
//         order.push(num);
//     }

//     for(int i=0;i<order.size();++i){
//         int temp = order.top();
//         order.pop();
//         printf("%d ", temp);
//     }

//     // printf("%d", order.top());
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// static int num;

// void merge(int* array, int *temp, int begin1, int end1, int begin2, int end2){
    
//     int element_num = end2-begin1+1;

//     int i=begin1, j=begin2, k=0;
//     for(;i<=end1&&j<=end2;++k){
//         if(array[i] < array[j]){
//             temp[k] = array[i];
//             ++i;
//         }else{
//             temp[k] = array[j];
//             ++j;
//         }
//     }

//     if(i<=end1){
//         for(;i<=end1;++i, ++k){
//             temp[k] = array[i];
//         }
//     }

//     if(j<=end2){
//         for(;j<=end2;++j, ++k){
//             temp[k] = array[j];
//         }
//     }

//     int temp_i = 0;
//     for(;temp_i<element_num;++temp_i){
//         array[begin1+temp_i] = temp[temp_i];
//     }
// }

// void mergeAndSort(int* array, int* temp, int begin, int end){
//     if(begin==end) return;
//     int middle = (begin+end)/2;
//     mergeAndSort(array, temp, begin, middle);
//     mergeAndSort(array, temp, middle+1, end);
//     merge(array, temp, begin, middle, middle+1, end);
// }

// int main(void){
//     scanf("%d", &num);

//     int *array  = (int*)malloc(num*sizeof(int));
//     int *temp   = (int*)malloc(num*sizeof(int));

//     int i=0;
//     for(;i<num;++i){
//         scanf("%d", array+i);
//     }

//     mergeAndSort(array, temp, 0, num-1);

//     printf("%d", array[(num-1)/2]);

//     // for(i=0;i<num;++i){
//     //     printf("%d ", array[i]);
//     // }

//     // int continue_num=1;
//     // int possible_majority=-1;
//     // for(i=1;i<num;++i){
//     //     if(array[i] == array[i-1]){
//     //         ++continue_num;
//     //         possible_majority = array[i];
//     //         if(continue_num > num/2){
//     //             printf("%d", possible_majority);
//     //             break;
//     //         }
//     //     }else{
//     //         continue_num = 1;
//     //         possible_majority = -1;
//     //     }
//     // }

//     free(array);
//     free(temp);
//     return 0;
// }