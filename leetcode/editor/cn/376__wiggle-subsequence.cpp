#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;




//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int curDiff = 0;    //  当前一对的差
        int preDiff = 0;    //  前面一对的差
        int res = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i + 1] - nums[i];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)){
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    auto res = solution.wiggleMaxLength(nums);
    cout<<res;
    return 0;
}