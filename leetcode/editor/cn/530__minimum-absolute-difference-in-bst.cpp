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
private:
    int minum = INT_MAX;
    TreeNode* pre = nullptr;
    void getMinum(TreeNode* node){
        if(node == nullptr)
            return;
        getMinum(node->left);
        if(pre)
            minum = min(minum,node->val - pre->val);
        pre = node;
        getMinum(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr)
            return minum;
        int left = getMinimumDifference(root->left);
        minum = min(minum,left);
        if(pre != nullptr)
            minum = min(minum,root->val - pre->val);
        pre = root;
        int right = getMinimumDifference(root->right);
        minum = min(minum,right);
//        getMinum(root);
        return minum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}