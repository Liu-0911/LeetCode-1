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
    int longestPalindromeSubseq(const string &s) {
        //  dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            //  注意因为dp[i][j]的定义，所以j一定是大于等于i的，那么在填充dp[i][j]的时候一定是只填充右上半部分。
            for (int j = i + 1; j < s.size(); j++) {
//                cout<<i<<" "<<j<<"--";
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
//            cout<<endl;
        }
        return dp[0][s.size() - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "abcde";
    cout<<s.size()<<endl;
    cout<<solution.longestPalindromeSubseq (s);
    return 0;
}