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
    //  dp[i][j][k] 表示输入字符串在子区间 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量。
    //  压缩存储状态，使用滚动数组dp[i][j]表示能够使用 i 个 0 和 j 个 1 的字符串的最大数量。
        //  因为使用了滚动数组压缩状态，所以遍历顺序需要外层for循环遍历物品，内层for循环遍历容量且从后向前遍历
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(const auto& str : strs){   //  遍历物品
            int numOfZero = 0;
            int numOfOne = 0;
            for(const auto &c : str){
                if(c == '0')
                    numOfZero++;
                else
                    numOfOne++;
            }
            for(int i = m; i >= numOfZero; i--){    //  遍历背包容量
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