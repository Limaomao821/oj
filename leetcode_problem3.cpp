#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.length();
        if(num == 0) return 0;
        int i=0, j=0;
        int max=0;
        int **record = (int**)malloc(sizeof(int*)*num);
        for(i=0; i<num; ++i) {
            record[i] = (int*)malloc(sizeof(int)*(num-i));
        }
        record[0][0] = 1;
        (max < record[0][0]) ? (max = record[0][0]) : (max = max);
        for(i=0, j=1; j<num; ++j){
            if(s[j] == s[i]) record[i][j] = 0;
            else record[i][j] = record[i][j-1];
            (max < record[i][j]) ? (max = record[i][j]) : (max = max);
        }
        for(i=1; i<num; ++i){
            record[i][0] = record[i-1][1]+1;
            (max < record[i][0]) ? (max = record[i][0]) : (max = max);
            for(j=1; j<num-i; ++j){
                if(s[i] == s[j+i]) record[i][j] = 0;
                else{
                    int a = record[i][j-1];
                    int b = record[i-1][j+1] + 1;
                    record[i][j] = (a > b) ? b : a;
                }
                (max < record[i][j]) ? (max = record[i][j]) : (max = max);
            }
        }
        
        return max;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int num = s.length();
//         int i=0, j=0;
//         int max=0;
//         int **record = (int**)malloc(sizeof(int*)*num);
//         for(i=0; i<num; ++i) {
//             record[i] = (int*)malloc(sizeof(int)*num);
//         }
//         record[0][0] = 1;
//         for(i=0, j=1; j<num; ++j){
//             if(s[j] == s[i]) record[i][j] = 0;
//             else record[i][j] = record[i][j-1];
//             (max < record[i][j]) ? (max = record[i][j]) : (max = max);
//         }
//         for(i=1; i<num; ++i){
//             record[i][i] = record[i-1][i]+1;
//             (max < record[i][i]) ? (max = record[i][i]) : (max = max);
//             for(j=i+1; j<num; ++j){
//                 if(s[i] == s[j]) record[i][j] = 0;
//                 else{
//                     int a = record[i][j-1];
//                     int b = record[i-1][j] + 1;
//                     record[i][j] = (a > b) ? b : a;
//                     (max < record[i][j]) ? (max = record[i][j]) : (max = max);
//                 }
                
//             }
//         }
        
//         return max;
//     }
// };