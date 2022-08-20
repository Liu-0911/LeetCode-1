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
    vector<vector<int>> res;
    vector<int> path;
public:
//    void dfs(TreeNode* node,int targetsum){
//        if(!node->left && !node->right && targetsum == 0){
//            res.emplace_back(path);
//            return;
//        }
//        if(!node->left && !node->right)
//            return;
//        if(node->left){
//            path.emplace_back(node->left->val);
//            dfs(node->left,targetsum - node->left->val);
//            path.pop_back();
//        }
//        if(node->right){
//            path.emplace_back(node->right->val);
//            dfs(node->right,targetsum - node->right->val);
//            path.pop_back();
//        }
//
//    }
//
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        res.clear();
//        path.clear();
//        if(root == nullptr)
//            return res;
//        path.emplace_back(root->val);
//        dfs(root,targetSum - root->val);
//        return res;
//    }


    void dfs(TreeNode* node,int targetsum){
        if(node == nullptr)
            return;
        path.emplace_back(node->val);
        if(!node->left && !node->right ){
            if(targetsum == node->val){
                res.emplace_back(path);
            }
            path.pop_back();
            return;
        }
        dfs(node->left,targetsum - node->val);
        dfs(node->right,targetsum - node->val);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return res;
//        vector<int> path;
        dfs(root,targetSum);
        return res;
    }
};

//  未进行回溯优化的版本
//class Solution {
//private:
//    vector<vector<int>> res;
//public:
//    void dfs(TreeNode* node,vector<int> path,int targetsum){
//        if(node == nullptr)
//            return;
//        path.emplace_back(node->val);
//        if(!node->left && !node->right && targetsum == node->val){
//            res.emplace_back(path);
//            return;
//        }
//        dfs(node->left,path,targetsum - node->val);
//        dfs(node->right,path,targetsum - node->val);
//    }
//
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        if(root == nullptr)
//            return {};
//        vector<int> path;
//        dfs(root,path,targetSum);
//        return res;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}