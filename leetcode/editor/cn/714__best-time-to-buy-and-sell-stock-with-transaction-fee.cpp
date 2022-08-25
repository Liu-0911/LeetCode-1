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
//            if(prices[i] < minPrice)    //  �����ǰ�۸�С����С�۸��൱������һֻ�µĹ�Ʊ
//                minPrice = prices[i];
//            else if(prices[i] > minPrice + fee){    //  �����ǰ�۸�����������ۼ������ѣ�����������������
//                res += prices[i] - minPrice - fee;
//                minPrice = prices[i] - fee;    //  ����������һ֧��Ʊʱ�����Ǿ��������������ͬ�۸����������������һ֧��Ʊ��Ȩ�����������Կ��ǵ������Ǽ۵����
//            } else{ //  ����۸�����С�۸���С�۸��������֮���򲻽��в���
//                continue;
//            }
//        }
//        return res;
//    }

    //  ��̬�滮
    //  dp[i][0] ��ʾ��i�첻���й�Ʊ�����ֽ�
    //  dp[i][1] ��ʾ��i����й�Ʊ��������ֽ�
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
//        vector<vector<int>> dp(n, vector<int>(2, 0));
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0]; // �ֹ�Ʊ
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