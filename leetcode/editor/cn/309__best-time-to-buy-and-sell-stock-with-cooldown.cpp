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
    //  ��Ҫ��ע�䶳�ڣ�Ҫ��ע���������ڣ���Ϊ�䶳��Ϊ�����ĺ�һ�죬���������������ʱ����Ҫ�ж�һ��ǰһ���Ƿ�ո���������
    //  �����Ҫ�Բ����й�Ʊ��״̬����ϸ�֣�1 ������û�� 2 ��Ϊ�������µ�û�й�Ʊ�������䶳�ڣ�
    //  ���dp����һ������״̬
    //  dp[i][0]    �����й�Ʊ��û����������
    //  dp[i][1]    ���й�Ʊ
    //  dp[i][2]    ���ֹɲ��ҵ�������������
    //  ״̬ת�Ʒ���
    //  ��i�첻�ֹ���û������״̬dp[i][0]��Ҳ������û�й�Ʊ�����һ�������Ϊ����������û�еģ��ǻ��仰˵�Ǵ�i-1�쵽��i��ת��ʱ����ѹ����û���ҹ�Ʊ������i-1��һ��Ҳ�ǲ����У��Ǿ��ǲ����е����ֿ��ܣ�i-1�첻�ֹ��ҵ���û������dp[i-1][0]��i-1�첻�ֹɵ��ǵ�������ȥ��dp[i-1][2]��
    //  ���ԣ� dp[i][0]=max(dp[i-1][0],dp[i-1][2])
    //
    //  ��i��ֹ�dp[i][1]�������ҳֹɣ��������ֿ��ܣ�
    //  1��Ҫô�������Ҿͳֹɣ�����̳�����ģ�Ҳ����dp[i-1][1]�����ֿ��ܺܺ���⣻
    //  2��!!!!Ҫô���������Ҳ��ֹɣ�����������ģ���ǰ����������һ��û������Ϊ������������ˣ���ô�����Ҳ��ܽ��ף�Ҳ������Ŀ����ν���䶳�ڡ��ĺ��壬ֻ�������ǡ����ֹ��ҵ���û���������״̬���ҽ���������룡������dp[i-1][0]-p[i]
    //  ���ԣ� dp[i][1]=max(dp[i-1][1],dp[i-1][0]-p[i])
    //
    //  ����i�첻�ֹ��ҵ��������ˣ����־ͼ��ˣ��Ǿ���˵������һ���ǳֹɵģ�Ҫ��Ȼ�ҽ�����ʲô���������ֹ�ֻ��һ��״̬������ֹɵ�������Ͻ��������õ��������棬����dp[i-1][1]+p[i]��
    //���ԣ�dp[i][2]=dp[i-1][1]+p[i]
    //

    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
//        vector<vector<int>> dp(prices.size(),vector<int> (3,0));
        auto dp = new int [prices.size()][3];
        dp[0][0] = 0;   //�����Ͳ����У�ɶҲû��
        dp[0][1] = -prices[0];  //�����Ʊ
        dp[0][2] = 0;   //�Ƿ�״̬������Ϊ�˲�Ӱ������ʼ��Ϊ0
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

    //  ѹ���ռ䡪����������
//    int maxProfit(vector<int>& prices) {
//        if(prices.size() < 2)
//            return 0;
////        vector<vector<int>> dp(2,vector<int> (3,0));
//        int dp[2][3] = {0};
//        dp[0][0] = 0;   //�����Ͳ����У�ɶҲû��
//        dp[0][1] = -prices[0];  //�����Ʊ
//        dp[0][2] = 0;   //�Ƿ�״̬������Ϊ�˲�Ӱ������ʼ��Ϊ0
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