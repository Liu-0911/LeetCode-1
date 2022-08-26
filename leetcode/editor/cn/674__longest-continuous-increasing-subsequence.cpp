#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //  和300题的区别是要求连续递增子序列
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int res = 1;
        vector<int> dp(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){  //  这里是和300题最大的区别，因为要求连续所以遍历i之前（因为必须连续，不能中断）
                dp[i] = dp[i - 1] + 1;
            }
            res = res > dp[i] ? res : dp[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}