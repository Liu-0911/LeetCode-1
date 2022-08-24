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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //dp[0]为不偷当前节点，dp[1]为偷当前节点
private:
    vector<int> robTree(TreeNode *cur){
        if(cur == nullptr)
            return {0,0};
        //  这里要进行后序遍历，因为需要孩子结点的结果
        vector<int> left = robTree((cur->left));
        vector<int> right = robTree((cur->right));
        //  偷当前结点
        int val1 = cur->val + left[0] + right[0];
        //  不偷当前节点 则可以偷孩子结点（偷不偷还是取决于哪一个值大）
        int val2 = max(left[0],left[1]) + max(right[0],right[1]);
//        int val2 = left[1] + right[1];    有可能偷孩子结点的结果小于不偷孩子结点，因此需要判断
        return {val2,val1};
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0],res[1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}