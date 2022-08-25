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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        vector<int> dp(nums.size(),1);  //  子序列的长度最小为1，dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
        int res = 1;
        for(int i = 0; i < nums.size(); i++){   //  遍历数组
            for(int j = 0; j < i; j++){ //  使用j遍历0到i-1，取dp[j] + 1的最大值
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);  //注意这里不是要dp[i] 与 dp[j] + 1进行比较，而是我们要取dp[j] + 1的最大值。
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