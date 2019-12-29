#include <vector>
#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> record;
        for(int i=0; i<nums.size(); ++i){
            record.insert(make_pair(nums[i], i));
        }
        vector<int> ans;
        map<int, int>::iterator find;
        for(int i=0; i<nums.size(); ++i){
            int need = target - nums[i];
            find = record.find(need); 
            if((find != record.end()) && find->second != i) {
                ans.push_back(i);
                ans.push_back(find->second);
                break;
            }
        }
        return ans;
    }
};