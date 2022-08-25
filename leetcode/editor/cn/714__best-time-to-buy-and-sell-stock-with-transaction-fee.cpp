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

//    int maxProfit(vector<int>& prices, int fee) {
//        int res = 0;
//        int minPrice = INT32_MAX;
//        for(int i = 0; i < prices.size(); i++){
//            if(prices[i] < minPrice)    //  如果当前价格小于最小价格，相当于买入一只新的股票
//                minPrice = prices[i];
//            else if(prices[i] > minPrice + fee){    //  如果当前价格大于最低买入价加手续费，则卖出并计算利润
//                res += prices[i] - minPrice - fee;
//                minPrice = prices[i] - fee;    //  当我们卖出一支股票时，我们就立即获得了以相同价格并且免除手续费买入一支股票的权利，这样可以考虑到连续涨价的情况
//            } else{ //  如果价格在最小价格到最小价格加手续费之间则不进行操作
//                continue;
//            }
//        }
//        return res;
//    }

    //  动态规划
    //  dp[i][0] 表示第i天不持有股票所得现金。
    //  dp[i][1] 表示第i天持有股票所得最多现金
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
//        vector<vector<int>> dp(n, vector<int>(2, 0));
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] -fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] );
        }
        return dp[n - 1][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}