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
    //  不要关注冷冻期，要关注卖出的日期，因为冷冻期为卖出的后一天，所以我们在想买的时候需要判断一下前一天是否刚刚卖出即可
    //  因此需要对不持有股票的状态进行细分，1 本来就没有 2 因为卖出导致的没有股票（会有冷冻期）
    //  因此dp数组一共三种状态
    //  dp[i][0]    不持有股票且没有卖出操作
    //  dp[i][1]    持有股票
    //  dp[i][2]    不持股并且当天有卖出操作
    //  状态转移方程
    //  第i天不持股且没卖出的状态dp[i][0]，也就是我没有股票，而且还不是因为我卖了它才没有的，那换句话说是从i-1天到第i天转移时，它压根就没给我股票！所以i-1天一定也是不持有，那就是不持有的两种可能：i-1天不持股且当天没有卖出dp[i-1][0]；i-1天不持股但是当天卖出去了dp[i-1][2]；
    //  所以： dp[i][0]=max(dp[i-1][0],dp[i-1][2])
    //
    //  第i天持股dp[i][1]，今天我持股，来自两种可能：
    //  1、要么是昨天我就持股，今天继承昨天的，也就是dp[i-1][1]，这种可能很好理解；
    //  2、!!!!要么：是昨天我不持股，今天我买入的，但前提是昨天我一定没卖！因为如果昨天我卖了，那么今天我不能交易！也就是题目中所谓“冷冻期”的含义，只有昨天是“不持股且当天没卖出”这个状态，我今天才能买入！所以是dp[i-1][0]-p[i]
    //  所以： dp[i][1]=max(dp[i-1][1],dp[i-1][0]-p[i])
    //
    //  三、i天不持股且当天卖出了，这种就简单了，那就是说昨天我一定是持股的，要不然我今天拿什么卖啊，而持股只有一种状态，昨天持股的收益加上今天卖出得到的新收益，就是dp[i-1][1]+p[i]啦
    //所以：dp[i][2]=dp[i-1][1]+p[i]
    //

    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
//        vector<vector<int>> dp(prices.size(),vector<int> (3,0));
        auto dp = new int [prices.size()][3];
        dp[0][0] = 0;   //本来就不持有，啥也没干
        dp[0][1] = -prices[0];  //买入股票
        dp[0][2] = 0;   //非法状态，但是为了不影响后面初始化为0
//        print(dp);
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i-1][1]+prices[i];
//            print(dp);
        }
        return max(dp[prices.size() - 1][2],dp[prices.size() - 1][0]);
//        return max(max(dp[prices.size() - 1][2],dp[prices.size() - 1][0]),dp[prices.size() - 1][1] + prices[prices.size() - 1]);
    }
//    void print(const vector<vector<int>> &dp){
//        for(auto n : dp){
//            for(auto n1 : n)
//                cout<<n1<<"  ";
//            cout<<endl;
//        }
//        cout<<endl;
//    }

    //  压缩空间——滚动数组
//    int maxProfit(vector<int>& prices) {
//        if(prices.size() < 2)
//            return 0;
////        vector<vector<int>> dp(2,vector<int> (3,0));
//        int dp[2][3] = {0};
//        dp[0][0] = 0;   //本来就不持有，啥也没干
//        dp[0][1] = -prices[0];  //买入股票
//        dp[0][2] = 0;   //非法状态，但是为了不影响后面初始化为0
////        print(dp);
//        for(int i = 1; i < prices.size(); i++){
//            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]);
//            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - prices[i]);
//            dp[i % 2][2] = dp[(i - 1) % 2][1]+prices[i];
////            print(dp);
//        }
//        return max(dp[(prices.size() - 1) % 2][2],dp[(prices.size() - 1) % 2][0]);
////        return max(max(dp[prices.size() - 1][2],dp[prices.size() - 1][0]),dp[prices.size() - 1][1] + prices[prices.size() - 1]);
//    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> prices = {1,2,3,0,2};
    solution.maxProfit(prices);
    return 0;
}