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
    // 非递归
//    vector<double> averageOfLevels(TreeNode* root) {
//        queue<TreeNode*> que;
//        if(root != nullptr) que.push(root);
//        vector<double> res;
//        while(!que.empty()){
//            int numOfNode = que.size();
//            double sum = 0;
//            for(int i = 0;i < numOfNode; i++){
//                TreeNode *cur = que.front();
//                que.pop();
//                sum += cur->val;
//                if(cur->left) que.push(cur->left);
//                if(cur->right) que.push(cur->right);
//            }
//            res.emplace_back(sum / numOfNode);
//        }
//        return res;
//    }

    // 递归
    void dfs(TreeNode *cur,vector<double> &res,int depth,vector<int> &num){
        if(cur == nullptr)
            return;
        double sum = 0;
        if(res.size() > depth){     // 若res.size > 当前深度说明当前层已经有节点被访问过了
            res[depth] += cur->val;
            num[depth]++;
        } else{
            res.emplace_back(cur->val);
            num.emplace_back(1);
        }
        dfs(cur->left,res,depth + 1,num);
        dfs(cur->right,res,depth + 1,num);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> num;
        int depth = 0;
        dfs(root,res,depth,num);
        for(int i = 0;i < res.size();i++){
            res[i] /= num[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}