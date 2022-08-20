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
    int cout,maxCout;
    TreeNode* pre;
    vector<int> res;
    void dfs(TreeNode* node){
        if(node == nullptr)
            return;
        dfs(node->left);    //  左子树

        //  此结点
        if(pre == nullptr)  //  第一个结点
            cout = 1;
        else if(pre->val == node->val)  //  两个结点值相等
            cout++;
        else    //  两个结点值不相等
            cout = 1;
        pre = node;
        if(cout == maxCout)
            res.emplace_back(node->val);
        if(cout > maxCout){
            maxCout = cout;
            res.clear();    //  注意如果当前字符个数已经超过记录的最大值，要清空结果
            res.emplace_back(node->val);
        }

        dfs(node->right);   //  右子树
        return ;
    }
public:
    vector<int> findMode(TreeNode* root) {
        cout = 0;
        maxCout = 0;
        pre = nullptr;
        res.clear();
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}