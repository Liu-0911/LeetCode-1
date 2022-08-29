#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //  贪心
//    int maxSubArray(vector<int>& nums) {
//        int result = INT32_MIN;
//        int count = 0;
//        for(int i = 0; i < nums.size(); i++){
//            count += nums[i];
//            if(count > result)
//                result = count;
//            if(count <= 0)
//                count = 0;
//        }
//        return result;
//    }
    //  动态规划
    int maxSubArray(vector<int>& nums){
        if(nums.size() < 1)
            return 0;
            //  可以压缩dp数组
//        vector<int> dp(nums.size(),0);
//        dp[0] = nums[0];
//        int res = dp[0];
//        for(int i = 1; i < nums.size(); i++){
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            res = max(res,dp[i]);
//        }
            //  压缩后
        int tmp = nums[0];
        int res = tmp;
        for(int i = 1; i < nums.size(); i++){
            tmp = max(tmp + nums[i],nums[i]);
            res = max(res,tmp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}