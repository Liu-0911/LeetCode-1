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
    int numDistinct(string s, string t) {
        // dp[i][j]����i-1Ϊ��β���ַ���s�������г�����j-1Ϊ��β���ַ���t�ĸ���Ϊdp[i][j]��
        vector<vector<size_t>> dp(s.size() + 1, vector<size_t> (t.size() + 1, 0));
        //  ��һ��Ϊ����ӦΪ��ʱtΪ�գ����ַ����������ַ������ִ�������Ϊ1
        for(int i = 0; i < s.size(); i++)
            dp[i][0] = 1;
        //  ��һ��Ϊ1��ӦΪ��ʱsΪ�գ����ַ����޷����t
        for(int j = 1; j < t.size(); j++)
            dp[0][j] = 0;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                //  ����ƥ���ַ���
                //  s: babgbag      ��ƥ�䵽�����һλ��������ͬ�� 1 ��s[i]ȡƥ��t[j] ����> ���� babgba �� ba ��dp[i - 1][j - 1]��
                //  t: bag                                     2 ����s[i]ȡƥ��t[j] ����> ���� babgba �� bag ��dp[i - 1][j]��
                //                                    ���߲�ͬ�� ֻ�ܲ���s[i]ȡƥ��t[j] ����> ���� babgba �� bag ��dp[i - 1][j]��
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}