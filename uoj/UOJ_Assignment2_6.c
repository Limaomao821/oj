#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int testNum;
    scanf("%d", &testNum);

    while(testNum--){
        int len1, len2;
        scanf("%d%d", &len1, &len2);
        getchar();
        char *str1 = (char*)malloc(sizeof(char)*len1);
        char *str2 = (char*)malloc(sizeof(char)*len2);

        int temp;
        for(temp=0;temp<len1;++temp){
            scanf("%c", &str1[temp]);
        }
        getchar();
        for(temp=0;temp<len2;++temp){
            scanf("%c", &str2[temp]);
        }
        getchar();

        short **table = (short**)malloc(sizeof(short*)*len1);
        for(temp=0;temp<len1;++temp){
            table[temp] = (short*)malloc(sizeof(short)*len2);
            memset(table[temp], 0, sizeof(short)*len2);
        }

        int temp1, temp2;
        if(str1[0]==str2[0]) table[0][0]=1;
        for(temp2=1;temp2<len2;++temp2){
            if(str1[0]==str2[temp2]) table[0][temp2] = 1;
            else table[0][temp2] = table[0][temp2-1];
        }
        for(temp1=1;temp1<len1;++temp1){
            if(str1[temp1]==str2[0]) table[temp1][0] = 1;
            else table[temp1][0] = table[temp1-1][0];
        }

        for(temp1=1;temp1<len1;++temp1){
            for(temp2=1;temp2<len2;++temp2){
                int a=table[temp1-1][temp2-1];
                if(str1[temp1]==str2[temp2]) a+=1;
                int b=table[temp1-1][temp2];
                int c=table[temp1][temp2-1];

                int max=a;
                if(b>max) max=b;
                if(c>max) max=c;
                table[temp1][temp2] = max;
            }
        }

        printf("%hd\n", table[len1-1][len2-1]);
    }


    return 0;
}