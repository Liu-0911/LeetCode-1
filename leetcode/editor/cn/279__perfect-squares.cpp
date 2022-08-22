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
//    int numSquares(int n) {
//        vector<int> dp(n + 1, INT32_MAX);
//        dp[0] = 0;
//        for(int i = 1; i * i <= n; i++){
//            for(int j = i * i; j <= n; j++){
//                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
////                dp[j] = dp[j - i * i] + 1;
//            }
//
//        }
//        return dp[n];
//    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        int di = 1;
        for(int i = di * di; i <= n; di++, i = di * di){
            for(int j = i; j <= n; j++){
                dp[j] = min(dp[j - i] + 1, dp[j]);
//                dp[j] = dp[j - i * i] + 1;
            }

        }
        return dp[n];
    }
//    int numSquares(int n) {
//        vector<int> dp(n + 1,0);
//        dp[0] = 0;
//        for(int i = 1; i <= n; i++){
//            dp[i] = i;
//            for(int j = 1; j <= i / j; j++){
//                dp[i] = min(dp[i - j * j] + 1, dp[i]);
//            }
//        }
//        return dp[n];
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}