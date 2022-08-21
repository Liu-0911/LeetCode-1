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
    //  dp[i][j][k] ��ʾ�����ַ����������� [0, i] �ܹ�ʹ�� j �� 0 �� k �� 1 ���ַ��������������
    //  ѹ���洢״̬��ʹ�ù�������dp[i][j]��ʾ�ܹ�ʹ�� i �� 0 �� j �� 1 ���ַ��������������
        //  ��Ϊʹ���˹�������ѹ��״̬�����Ա���˳����Ҫ���forѭ��������Ʒ���ڲ�forѭ�����������ҴӺ���ǰ����
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(const auto& str : strs){   //  ������Ʒ
            int numOfZero = 0;
            int numOfOne = 0;
            for(const auto &c : str){
                if(c == '0')
                    numOfZero++;
                else
                    numOfOne++;
            }
            for(int i = m; i >= numOfZero; i--){    //  ������������
                for(int j = n; j >= numOfOne; j--){
                    dp[i][j] = max(dp[i][j], dp[i - numOfZero][j - numOfOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}