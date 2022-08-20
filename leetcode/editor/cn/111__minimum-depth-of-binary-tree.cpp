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
    int minDepth(TreeNode* root) {

        // 非递归版 BFS
//        queue<TreeNode*> que;
//        if(root != nullptr) que.push(root);
//        int depth = 0;
//        while(!que.empty()){
//            int size = que.size();
//            depth++;
//            TreeNode* cur;
//            for(int i = 0;i < size;i++){
//                cur = que.front();
//                que.pop();
//                if(cur->left) que.push(cur->left);
//                if(cur->right) que.push(cur->right);
//                if(cur->left == nullptr && cur->right == nullptr)
//                    return depth;
//            }
//        }
//        return depth;

        // 递归版DFS
        if(root == nullptr)
            return 0;
//        if(!root->left && !root->right)
//            return 1;
        if(root->left != nullptr && root->right != nullptr)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else
            return max(minDepth(root->left), minDepth(root->right)) + 1;
//            return minDepth(root->left) + minDepth(root->right) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}