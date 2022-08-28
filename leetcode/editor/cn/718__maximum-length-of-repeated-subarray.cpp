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
    //  dp[i][j] �����±�i - 1Ϊ��β��A�������±�j - 1Ϊ��β��B����ظ������鳤��Ϊdp[i][j]
    //  ��Ϊѭ����dp[i][j]������dp[i - 1][j - 1]������Ҫ��dp����������һ��0
    //  ���������ʼ������ʼ��ʱ��dp[i][0]��dp[0][j]��Ϊ0Ȼ������Ϳ��Լ������������

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int> (nums2.size() + 1, 0));
        int res = 0;
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = res > dp[i][j] ? res : dp[i][j];
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}