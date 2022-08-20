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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
//    void order(TreeNode* cur,vector<int>& res,int depth){
//        if(cur == nullptr)
//            return;
//        // 先访问 当前节点，再递归地访问 右子树 和 左子树。
//        if(res.size() == depth)
//            res.emplace_back(cur->val); // 如果当前节点所在深度还没有出现在res里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入res中。
//        order(cur->right,res,depth + 1);
//        order(cur->left,res,depth + 1);
//
//    }
//    vector<int> rightSideView(TreeNode* root) {
//        vector<int> res;
//        int depth = 0;
//        order(root,res,depth);
//        return res;
//    }
    // 非递归
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()){
            int numOfNode = que.size();
            TreeNode *node = nullptr;
            for(int i = 0;i < numOfNode;i++){
                node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.emplace_back(node->val);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}