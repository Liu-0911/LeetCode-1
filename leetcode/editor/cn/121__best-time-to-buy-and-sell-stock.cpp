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
    // 我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice
//    int maxProfit(vector<int>& prices) {
//        int minPrice = INT_MAX;
//        int MaxProfit = 0;
//        for(auto price : prices){
//            minPrice = min(minPrice,price);
//            MaxProfit = max(MaxProfit,price - minPrice);
//        }
//        return MaxProfit;
//    }
    //  动态规划
    //  dp[i][0]表示今天不持股
        //  昨天不持股，今天什么都不做；
        //  昨天持股，今天卖出股票（现金数增加）
    //  dp[i][1]表示今天持股
        //  昨天持股，今天什么都不做（现金数与昨天一样）；
        //  昨天不持股，今天买入股票（注意：只允许交易一次，因此手上的现金数就是当天的股价的相反数）。
//    int maxProfit(vector<int>& prices) {
//        if(prices.size() < 2)
//            return 0;
//        vector<vector<int>> dp(prices.size(),vector<int> (2,0));
//        dp[0][0] = 0;
//        dp[0][1] = -prices[0];
//        for(int i = 1; i < prices.size(); i++){
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//            dp[i][1] = max(dp[i - 1][1], -prices[i]);   //  因为只能交易一次，所以此时现金数是股价的相反数
//        }
//        return dp[prices.size() - 1][0];
//    }
    //  滚动数组优化版本
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<vector<int>> dp(2,vector<int> (2,0));    //  这里只开辟了一个2 * 2大小的数组
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);   //  因为只能交易一次，所以此时现金数是股价的相反数
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}