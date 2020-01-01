#include <string>
using namespace std;

// old version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.length();
        if(num == 0) return 0;
        int i=0, j=0;
        int max=0;
        int *last = (int*)malloc(sizeof(int)*num);
        int *now  = (int*)malloc(sizeof(int)*(num));

        last[0] = 1;
        (max < last[0]) ? (max = last[0]) : (max = max);
        for(i=0, j=1; j<num; ++j){
            if(s[j] == s[i]) last[j] = 0;
            else last[j] = last[j-1];
            (max < last[j]) ? (max = last[j]) : (max = max);
        }

        for(i=1; i<num; ++i){
            now[i] = last[i]+1;
            (max < now[i]) ? (max = now[i]) : (max = max);
            for(j=i+1; j<num; ++j){
                if(s[i] == s[j]) now[j] = 0;
                else{
                    int a = now[j-1];
                    int b = last[j] + 1;
                    now[j] = (a > b) ? b : a;
                }
                (max < now[j]) ? (max = now[j]) : (max = max);
            }
            int temp = i;
            for(temp=i; temp<num; ++temp){
                last[temp] = now[temp];
            }
        }
        
        free(last);
        free(now);
        return max;
    }
};

// new version
// Runtime: 4 ms, faster than 99.30% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 9.1 MB, less than 97.01% of C++ online submissions for Longest Substring Without Repeating Characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.length();
        if(num == 0) return 0;
        int max = 0;
        
        int record[128];
        for(int i=0; i<128; ++i) {
            record[i] = -1;
        }
        
        int length = 0;
        int start = 0;
        for(int i=0; i<num; ++i) {
            int lastPos = record[s[i]];
            if(lastPos == -1){
                ++length;
                
            } else if(lastPos < start) {
                ++length;
            } else {
                start = lastPos;
                length = i - lastPos;
            }
            record[s[i]] = i;
            (length > max) ? (max = length) : max;
        }
        
        return max;
    }
};