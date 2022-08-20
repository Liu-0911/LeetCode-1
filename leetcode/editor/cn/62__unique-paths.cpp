#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<string.h>

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

    int uniquePaths(int m, int n) {
        int dp[m][n] ;
        memset(dp,0,sizeof(dp));
    //�����岿��
    // 1 ȷ��dp���飨dp table���Լ��±�ĺ���
    //dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����
    // 2 ȷ�����ƹ�ʽ
    //��Ҫ��dp[i][j]��ֻ���������������Ƶ���������dp[i - 1][j] �� dp[i][j - 1]��
    //��ʱ�ڻع�һ�� dp[i - 1][j] ��ʾɶ���Ǵ�(0, 0)��λ�õ�(i - 1, j)�м���·����dp[i][j - 1]ͬ��
    //��ô����Ȼ��dp[i][j] = dp[i - 1][j] + dp[i][j - 1]����Ϊdp[i][j]ֻ�����������������
    // 3 dp����ĳ�ʼ��
    //��γ�ʼ���أ�����dp[i][0]һ������1����Ϊ��(0, 0)��λ�õ�(i, 0)��·��ֻ��һ������ôdp[0][j]Ҳͬ��
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int j = 0; j < n; j++)
            dp[0][j] = 1;
    // 4 ȷ������˳��
    //����Ҫ��һ�µݹ鹫ʽdp[i][j] = dp[i - 1][j] + dp[i][j - 1]��dp[i][j]���Ǵ����Ϸ������Ƶ���������ô������һ��һ������Ϳ����ˡ�
    //�����Ϳ��Ա�֤�Ƶ�dp[i][j]��ʱ��dp[i - 1][j] �� dp[i][j - 1]һ��������ֵ�ġ�
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}