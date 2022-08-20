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
//    void dfs(TreeNode *cur,vector<int> &res,int depth){
//        if(cur == nullptr)
//            return;
//        if(res.size() > depth){     // 若res.size > 当前深度说明当前层已经有节点被访问过了
//            res[depth] = cur->val > res[depth] ? cur->val : res[depth];
//        } else{
//            res.emplace_back(cur->val);
//        }
//        dfs(cur->left,res,depth + 1);
//        dfs(cur->right,res,depth + 1);
//    }
//    vector<int> largestValues(TreeNode* root) {
//        vector<int> res;
//        int depth = 0;
//        dfs(root,res,depth);
//        return res;
//    }
    // 非递归
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        vector<int> res;
        while(!que.empty()){
            int numOfNode = que.size();
            int maxnum = INT_MIN;
            for(int i = 0;i < numOfNode; i++){
                TreeNode *cur = que.front();
                que.pop();
                maxnum = cur->val > maxnum ? cur->val : maxnum;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.emplace_back(maxnum);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
//    auto a= INT32_MIN;
    cout<<INT64_MIN<<endl;
    cout<<INT32_MIN<<endl;
    cout<<INT_MIN<<endl;

    return 0;
}