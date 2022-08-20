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
    // 递归
    void order(TreeNode* cur,vector<vector<int>>& res,int depth){
        if(cur == nullptr)
            return;
        if(res.size() == depth)    // res.size 为res的行数，即res中有多少个一维vector
            res.emplace_back(vector<int>{});
        res[depth].emplace_back(cur->val);
        order(cur->left,res,depth + 1);
        order(cur->right,res,depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;
        order(root,res,depth);
        return res;
    }
    // 非递归
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        queue<TreeNode*> que;
//        vector<vector<int> > res;
//        if(root != nullptr)
//            que.push(root);
//        while(!que.empty()){
//            int numOfNode = que.size();
//            vector<int> layer;
//            for(int i = 0;i < numOfNode;i++){
//                TreeNode *node = que.front();
//                que.pop();
//                layer.emplace_back(node->val);
//                if(node->left) que.push(node->left);
//                if(node->right) que.push(node->right);
//            }
//            res.emplace_back(layer);
//        }
//        return res;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<vector<int>> res;
    res.emplace_back(vector<int>(3,10));
    res.emplace_back(vector<int>(2,10));
    res.emplace_back(vector<int>(1,10));
    cout<<res.size();
    return 0;
}