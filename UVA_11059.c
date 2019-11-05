#include<stdio.h>
#include<stdlib.h>

int main(void){
    int digit_num=0;
    int case_num=0;
    while(scanf("%d", &digit_num)!=EOF){
        ++case_num;

        int *digit_array = (int*)malloc(sizeof(int)*(digit_num+2));
        int *record = (int*)malloc(sizeof(int)*(digit_num+2));
        int *zero_position = (int*)malloc(sizeof(int)*(digit_num+2));

        digit_array[0]=0;
        record[0]=-1;
        zero_position[0]=0;
        int zero_position_pointer=1;

        int digit;
        int counter=1, negative_counter=0;
        for(counter=1;counter<digit_num+1;++counter){
            scanf("%d", &digit);
            digit_array[counter] = digit;
            if(digit<0){
                ++negative_counter;
                record[counter] = negative_counter;
            }else if(digit==0){
                record[counter] = -1;
                zero_position[zero_position_pointer] = counter;
                ++zero_position_pointer;
            }
        }
        digit_array[digit_num+1]=0;
        record[digit_num+1]=-1;
        zero_position[zero_position_pointer]=digit_num+1;
        ++zero_position_pointer;

        int maximum_product=0;
        int temp_zero_position_pointer=0;
        int current_zero_position = 0, last_zero_position = 0;
        for(temp_zero_position_pointer=0;temp_zero_position_pointer<zero_position_pointer;++temp_zero_position_pointer){
            current_zero_position = zero_position[temp_zero_position_pointer];
            
            int temp_maximum_product=0;

            if(record[current_zero_position-1]%2==0){
                int pointer=current_zero_position;
                for(;pointer>last_zero_position;--pointer){
                    if(record[pointer]%2==0){
                        break;
                    }
                }
                int temp;
                temp_maximum_product = 1;
                for(temp=last_zero_position+1;temp<=pointer;++temp){
                    temp_maximum_product *= digit_array[temp];
                }
            }else{
                int last_negative_place = current_zero_position-1;
                for(last_negativel_place=current_zero_position-1;last_negative_place>last_zero_position;--last_negative_place){
                    if(record[last_negative_place]!=record[last_negative_place-1]) break;
                }
                int temp_maximum_product_1=1, temp_maximum_product_2=1;
                int temp=last_zero_position+1;
                for(temp=last_zero_position+1;temp<last_negative_place;++temp){
                    temp_maximum_product_1 *= digit_array[temp];
                }
                for(temp=last_negative_place+1;temp<current_zero_position;++temp){
                    temp_maximum_product_2 *= digit_array[temp];
                }
                temp_maximum_product_1>temp_maximum_product_2?(temp_maximum_product=temp_maximum_product_1):(temp_maximum_product=temp_maximum_product_2);
            }
            

            if(temp_maximum_product > maximum_product) maximum_product=temp_maximum_product;

            last_zero_position = current_zero_position;
        }

        printf("Case #%d: The maximum product is %d.\n\n", case_num, maximum_product);
        free(record);
        free(zero_position);
    }
    return 0;
}