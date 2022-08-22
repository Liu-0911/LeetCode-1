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
private:
    void print(int amount, const vector<int>& dp){
        //  打印
        for(int j = 0; j <= amount; j++){
            cout<<dp[j] <<" ";
        }
        cout<<endl;
    }
public:
    //  完全背包
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        print(amount,dp);
        for(int i = 0; i < coins.size(); i++){  //  遍历物品
            cout<<"i = "<<i<<":   ";
            for(int j = coins[i]; j <= amount; j++){    //  遍历容量
                dp[j] += dp[j - coins[i]];
            }
            print(amount,dp);
        }
//        for (int j = 0; j <= amount; j++) { // 遍历背包容量
//            for (int i = 0; i < coins.size(); i++) { // 遍历物品
//                if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
//            }
//            cout<<"j = "<<j<<":   ";
//            print(amount,dp);
//        }
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    solution.change(amount,coins);

    return 0;
}