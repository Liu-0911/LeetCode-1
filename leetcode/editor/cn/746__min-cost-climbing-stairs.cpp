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
    //  �汾һ
    //  dp[i]�Ķ��壺�����i��̨�������ѵ���������Ϊdp[i]
    //  ÿһ��dp[i]��Ҫ����cost[i] ����ÿһ���ĳɱ���ǰ���㣬�൱�����һ������Ҫ����
public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int dp[cost.size()];
//        dp[0] = cost[0];
//        dp[1] = cost[1];
//        for(int i = 2; i < cost.size(); i++){
//            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//        }
//        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//    }
    //  �汾��
    //  ÿһ��dp[i]�Ļ��Ѷ���������һ�Σ��൱�����һ��Ҳ��Ҫ���㻨��
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return min(dp[cost.size() - 1] + cost[cost.size() - 1], dp[cost.size() - 2] + cost[cost.size() - 2]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}