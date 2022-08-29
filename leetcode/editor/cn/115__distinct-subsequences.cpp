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
        // dp[i][j]：以i-1为结尾的字符串s子序列中出现以j-1为结尾的字符串t的个数为dp[i][j]。
        vector<vector<size_t>> dp(s.size() + 1, vector<size_t> (t.size() + 1, 0));
        //  第一列为空是应为此时t为空，空字符串是所有字符串的字串，所以为1
        for(int i = 0; i < s.size(); i++)
            dp[i][0] = 1;
        //  第一行为1是应为此时s为空，空字符串无法组成t
        for(int j = 1; j < t.size(); j++)
            dp[0][j] = 0;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                //  例如匹配字符串
                //  s: babgbag      都匹配到了最后一位，两者相同则 1 用s[i]取匹配t[j] ——> 考察 babgba 和 ba （dp[i - 1][j - 1]）
                //  t: bag                                     2 不用s[i]取匹配t[j] ——> 考察 babgba 和 bag （dp[i - 1][j]）
                //                                    两者不同则 只能不用s[i]取匹配t[j] ——> 考察 babgba 和 bag （dp[i - 1][j]）
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