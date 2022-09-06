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
    //  保存子树序列化后的字符串空间复杂度太高，所以给每一棵子树一个唯一的编号来表示，减少空间复杂度
    // 结果
    vector<TreeNode *> res;
    // 子树字符串 到 唯一编号 的映射
    unordered_map<string, int> str2index;
    // 唯一编号 到 数量 的映射
    unordered_map<int, int> index2cnt;
    // 子树的编号，从1开始，用0表示是无效，后续递增来保证唯一
    int index = 1;
    // 返回当前节点子树的编号
    int dfs ( TreeNode *root ) {
        if ( root == nullptr ) return {};
        string str = to_string ( root->val ) + "," + to_string ( dfs ( root->left ) ) + "," + to_string ( dfs ( root->right ) );
        if ( str2index.find ( str ) == str2index.end () )//  没找到
        {
            str2index[ str ] = index;
            index++;
        }
        int tmp = str2index[ str ];
        index2cnt[ tmp ]++;
        // 首次发现重复，增加结果里
        if ( index2cnt[ tmp ] == 2 ) {
            res.emplace_back ( root );
        }
        return tmp;
    }
//    string dfs(TreeNode * root,vector<TreeNode*> &res, unordered_map<string, int>& mp ){
//        if(root==0) return {};
//        //二叉树先序序列化
//        string str = to_string(root->val) + "," + dfs(root->left, res, mp) + "," + dfs(root->right, res, mp);
//        if(mp[str] == 1){
//            res.emplace_back (root);
//
//        }
//        mp[str]++;
//        return str;
//    }
public:
    //  序列化每一刻子树
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//        unordered_map<string, int> mp;
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}