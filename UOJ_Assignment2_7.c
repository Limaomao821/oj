#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    short disk;
    short memory;
}require;

int main(void){
    int disk_total=0;
    int memory_total=0;
    int task_num=0;
    scanf("%d%d%d", &disk_total, &memory_total, &task_num);

    int** table = (int**)malloc(sizeof(int*)*(disk_total+1));
    require** require_table = (require**)malloc(sizeof(require*)*(disk_total+1));
    int temp1=0, temp2=0;
    for(temp1=0;temp1<disk_total+1;++temp1){
        table[temp1] = (int*)malloc(sizeof(int)*(memory_total+1));
        require_table[temp1] = (require*)malloc(sizeof(require)*(memory_total+1));
    }

    for(temp1=0;temp1<disk_total+1;++temp1){
        for(temp2=0;temp2<memory_total+1;++temp2){
            table[temp1][temp2] = 0;
            require_table[temp1][temp2].disk = 0;
            require_table[temp1][temp2].memory = 0;
        }
    }

    int temp3=0;
    for(temp3=0;temp3<task_num;++temp3){
        short int d_need=0;
        short int m_need=0;
        int user_num=0;
        scanf("%hd%hd%d", &d_need, &m_need, &user_num);

        int left_d = disk_total - d_need;
        int left_m = memory_total - m_need;
        for(temp1=left_d;temp1>=0;--temp1){
            for(temp2=left_m;temp2>=0;--temp2){
                int newValue = table[temp1][temp2] + user_num;
                if(newValue > table[d_need+temp1][m_need+temp2]) table[d_need+temp1][m_need+temp2] = newValue;
            }
        }
    }

    printf("%d", table[disk_total][memory_total]);

    return 0;
}