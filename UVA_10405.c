//Longest Common Subsequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char first[1001];
    char second[1001];
    int len1=0, len2=0;
    while(gets(first) != NULL){
        gets(second);
        len1 = strlen(first);
        len2 = strlen(second);

        if(len1==0 || len2==0){
            printf("0\n");
            continue;
        }
        short int **table = (short int**)malloc(sizeof(short int*)*len1);
        
        int temp1=0, temp2=0;
        for(temp1=0;temp1<len1;++temp1){
            table[temp1] = (short int*)malloc(sizeof(short int)*len2);
            memset(table[temp1], 0, sizeof(short int)*len2);
        }

        if(first[0]==second[0]) table[0][0]=1;
        for(temp2=1;temp2<len2;++temp2){
            if(first[0]==second[temp2]) table[0][temp2]=1;
            else table[0][temp2] = table[0][temp2-1];
        }
        for(temp1=1;temp1<len1;++temp1){
            if(first[temp1]==second[0]) table[temp1][0]=1;
            else table[temp1][0] = table[temp1-1][0];
        }

        int addon=0;
        for(temp1=1;temp1<len1;++temp1){
            for(temp2=1;temp2<len2;++temp2){
                addon=0;
                if(first[temp1]==second[temp2]) addon=1;
                table[temp1][temp2] = table[temp1-1][temp2-1]+addon;
                if(table[temp1-1][temp2] > table[temp1][temp2]) table[temp1][temp2] = table[temp1-1][temp2];
                if(table[temp1][temp2-1] > table[temp1][temp2]) table[temp1][temp2] = table[temp1][temp2-1];
            }
        }

        printf("%d\n", table[len1-1][len2-1]);
    }
    return 0;
}