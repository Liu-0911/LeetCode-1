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
    //0���ýڵ��޸���
    //1�����ڵ�������ͷ
    //2�����ڵ��и���
private:
    int res = 0;
    int dfs(TreeNode* node){
        if(node == nullptr)
            return 2;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left == 2 && right == 2)
            return 0;
        else if(left == 0 || right == 0){
            res++;
            return 1;
        }else
            return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if(dfs(root) == 0)
            res++;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}