#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        for(int num : nums2){
            if(nums.find(num) != nums.end()){
                res.emplace(num);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution sloution;
    return 0;
}