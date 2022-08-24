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
    //  与123题思路类似，不过将2次交易拓展到了k次
    //  dp[i][j]中 i表示第i天，j为 [0 - 2k-1] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
    //  0 没有操作
    //  1 第一次买入的状态（不一定是今天的买入操作，有可能维持前几天的买入状态）
    //  2 第一次卖出的状态
    //  3 第二次买入的状态
    //  4 第二次卖出的状态
    //  ...
    //  偶数就是卖出，奇数就是买入
    int maxProfit(int k,vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<vector<int>> dp(prices.size(),vector<int> (2 * k + 1,0));
        for(int i = 1; i < 2 * k + 1; i += 2){
            dp[0][i] = -prices[0];
        }
        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < 2 * k + 1; j += 2) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
//                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
//                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
//                dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];    //  因为处理过程中将n次买入的情况依赖于n-1次，因而最后n次的结果就是最大的
        }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}