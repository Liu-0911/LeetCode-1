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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int i = 0; i <= word2.size(); i++) dp[0][i] = i;
        //  当word1[i - 1] == word2[j - 1]时 则将以i-1结尾的字符串word1变成以j-1结尾的字符串word2的操作数和[i-2][j-2]相同
        //  当word1[i - 1] != word2[j - 1]时，则要分别讨论插入删除和替换三种情况
        //  删除时 1.word1删除一个元素，那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离 再加上一个操作。
        //        即 dp[i][j] = dp[i - 1][j] + 1;
        //        2.word2删除一个元素，那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离 再加上一个操作。
        //        即 dp[i][j] = dp[i][j - 1] + 1;
        //  插入时 word1插入一个字符相当于word2删除了一个字符，与删除情况合并
        //        例如 word1 = "ad",word2 = "a",word1删除元素'd' 和 word2添加一个元素'd',变成word1="a",word2="ad",最终的操作数是一样
        //  替换时 相当于不管两个字符串的最后一位，先把前面的串操作好，然后把word1的最后一位替换成word2的最后一位
        //        例如 word1 = "abcde",word2 = "fgh",先计算"abcd"和"fg"的操作数，这个操作数与"abcde"和"fge"的操作数相同，然后fge->fgh(abcde->abcdh);
        //        即 dp[i][j] = dp[i-1][j-1] + 1;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = min ({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
        return dp[word1.size()][word2.size()];
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}