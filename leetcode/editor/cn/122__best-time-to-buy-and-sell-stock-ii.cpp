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
//    int maxProfit(vector<int>& prices) {
//        int proFit = 0;
//        for(int i = 0;i < prices.size() - 1; i++){
//            int tmp = prices[i] - prices[i + 1];
//            if(tmp < 0)
//                proFit += tmp;
//        }
//        return -proFit;
//    }
//    int maxProfit(vector<int>& prices) {
//        int proFit = 0;
//        for(int i = 0;i < prices.size() - 1; i++){
//            int tmp = prices[i + 1] - prices[i];
//            if(tmp > 0)
//                proFit += tmp;
//        }
//        return proFit;
//    }
//  ��̬�滮
    //  dp[i][0]��ʾ���첻�ֹ�
    //  ���첻�ֹɣ�����ʲô��������
    //  ����ֹɣ�����������Ʊ���ֽ������ӣ�
    //  dp[i][1]��ʾ����ֹ�
    //  ����ֹɣ�����ʲô���������ֽ���������һ������
    //  ���첻�ֹɣ����������Ʊ��ע�⣺��121�ⲻͬ���������ν��ף�ע��dp[i][1]���Ƶ�����
//    int maxProfit(vector<int>& prices) {
//        if(prices.size() < 2)
//            return 0;
//        vector<vector<int>> dp(prices.size(),vector<int> (2,0));
//        dp[0][0] = 0;
//        dp[0][1] = -prices[0];
//        for(int i = 1; i < prices.size(); i++){
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);   //  ��Ϊ���Խ���������
//        }
//        return dp[prices.size() - 1][0];
//    }
    //  ���������Ż��汾
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        vector<vector<int>> dp(2,vector<int> (2,0));    //  ����ֻ������һ��2 * 2��С������
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - prices[i]);   //  ��Ϊ���Խ���������
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}