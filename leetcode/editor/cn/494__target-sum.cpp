#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include <numeric>
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum + target) & 1)
            return false;
        if(abs(target) > sum)
            return false;
        int bagSize = (sum + target) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}