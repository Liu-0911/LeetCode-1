#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include "math.h"

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
    //  经过数学证明，尽量将数字拆分为3，乘积最大，但是如果余数为1，则将一个3+1变成2+2（2*2 > 3*1）
//    int integerBreak(int n) {
//        if(n <= 3)
//            return n - 1;
//        int a = n / 3;
//        int b = n % 3;
//        if(b == 0)
//            return pow(3,a);
//        else if(b == 1)
//            return pow(3, a - 1) * 4;
//        else
//            return pow(3, a) * 2;
//    }
    //  动态规划
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}