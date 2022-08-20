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
public:
//    int getHeight(TreeNode* node){  //  返回当前节点为根节点的树的高度，若不是平衡二叉树则返回-1
//        if(node == nullptr)
//            return 0;
//        int leftHeight = getHeight(node->left);
//        if(leftHeight == -1)
//            return -1;
//        int rightHeight = getHeight(node->right);
//        if(rightHeight == -1)
//            return -1;
//        return abs(leftHeight - rightHeight) > 1 ? -1 : max(leftHeight,rightHeight) + 1;
//    }
//    bool isBalanced(TreeNode* root) {
//        if(root == nullptr)
//            return true;
//        return getHeight(root) == -1 ? false : true;
//    }

    // 优化版本，从低至顶计算，如果不是平衡二叉树直接返回（提前阻断）
    bool isBalanced(TreeNode* root)
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}