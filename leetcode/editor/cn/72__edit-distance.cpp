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
        //  ��word1[i - 1] == word2[j - 1]ʱ ����i-1��β���ַ���word1�����j-1��β���ַ���word2�Ĳ�������[i-2][j-2]��ͬ
        //  ��word1[i - 1] != word2[j - 1]ʱ����Ҫ�ֱ����۲���ɾ�����滻�������
        //  ɾ��ʱ 1.word1ɾ��һ��Ԫ�أ���ô�������±�i - 2Ϊ��β��word1 �� j-1Ϊ��β��word2������༭���� �ټ���һ��������
        //        �� dp[i][j] = dp[i - 1][j] + 1;
        //        2.word2ɾ��һ��Ԫ�أ���ô�������±�i - 1Ϊ��β��word1 �� j-2Ϊ��β��word2������༭���� �ټ���һ��������
        //        �� dp[i][j] = dp[i][j - 1] + 1;
        //  ����ʱ word1����һ���ַ��൱��word2ɾ����һ���ַ�����ɾ������ϲ�
        //        ���� word1 = "ad",word2 = "a",word1ɾ��Ԫ��'d' �� word2���һ��Ԫ��'d',���word1="a",word2="ad",���յĲ�������һ��
        //  �滻ʱ �൱�ڲ��������ַ��������һλ���Ȱ�ǰ��Ĵ������ã�Ȼ���word1�����һλ�滻��word2�����һλ
        //        ���� word1 = "abcde",word2 = "fgh",�ȼ���"abcd"��"fg"�Ĳ������������������"abcde"��"fge"�Ĳ�������ͬ��Ȼ��fge->fgh(abcde->abcdh);
        //        �� dp[i][j] = dp[i-1][j-1] + 1;
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