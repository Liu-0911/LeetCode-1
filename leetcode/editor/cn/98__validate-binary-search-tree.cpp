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
public:
    long long int min = INT64_MIN;    //  测试用例有INT最小值，用longlong最小值初始化
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        //  需要进行中序遍历，因为对二叉搜索树的中序遍历结果是一个有序数列，前序或者后序不行
//        if(root->val > min) min = root->val;
//        else return false;
//        bool leftbool = isValidBST(root->left);
//        bool rightbool = isValidBST(root->right);
        bool leftbool = isValidBST(root->left);
        if(root->val > min) min = root->val;
        else return false;
        bool rightbool = isValidBST(root->right);
        return leftbool && rightbool;
    }
//    TreeNode* pre = nullptr;    //  用来记录前一个结点
//    bool isValidBST(TreeNode* root) {
//        if(root == nullptr)
//            return true;
//        bool left = isValidBST(root->left);
//        if(pre != nullptr && pre->val >= root->val) return false;
//        pre = root;
//        bool right = isValidBST(root->right);
//        return left && right;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}