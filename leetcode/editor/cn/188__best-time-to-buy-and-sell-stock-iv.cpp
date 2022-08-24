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
    //  ��123��˼·���ƣ�������2�ν�����չ����k��
    //  dp[i][j]�� i��ʾ��i�죬jΪ [0 - 2k-1] ���״̬��dp[i][j]��ʾ��i��״̬j��ʣ����ֽ�
    //  0 û�в���
    //  1 ��һ�������״̬����һ���ǽ��������������п���ά��ǰ���������״̬��
    //  2 ��һ��������״̬
    //  3 �ڶ��������״̬
    //  4 �ڶ���������״̬
    //  ...
    //  ż������������������������
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
        return dp[prices.size() - 1][2 * k];    //  ��Ϊ��������н�n����������������n-1�Σ�������n�εĽ����������
        }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}