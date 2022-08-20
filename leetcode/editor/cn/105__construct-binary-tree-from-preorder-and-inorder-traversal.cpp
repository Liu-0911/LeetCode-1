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
    TreeNode* buildNode(vector<int>& inorder,int inorderBegin,int inorderEnd,vector<int>& preorder,int preorderBegin,int preorderEnd){
        if(inorderBegin == inorderEnd)
            return nullptr;
        int rootNodeValue = preorder[preorderBegin];  // 取后序遍历最后一个节点为根节点
        TreeNode *node = new TreeNode(rootNodeValue);

        if(inorderEnd - inorderBegin == 1)   // 如果遍历序列只有一个值即当前节点为根节点
            return node;

        int deIndex = 0;    //  找到分割点
        for(deIndex = inorderBegin;deIndex < inorderEnd;deIndex++)
            if(inorder[deIndex] == rootNodeValue)
                break;

//        vector<int> leftInorder(inorder.begin(),inorder.begin() + deIndex); //  切割得到中序遍历序列[0,deIndex) ——注意为左闭右开
//        vector<int> rightInorder(inorder.begin() + deIndex + 1,inorder.end());  //  切割得到中序遍历序列[deIndex+1,end) ——注意为左闭右开
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = deIndex;
        int rightInorderBegin = deIndex + 1;
        int rightInorderEnd = inorderEnd;

//        postorder.pop_back();   // 删除前序遍历的最后一个元素
        preorderBegin += 1;

//        vector<int> leftPostorder(postorder.begin(),postorder.begin() + leftInorder.size());    //  切割得到后序遍历序列[0,leftInorder.size) ——注意为左闭右开
//        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),postorder.end());    //  切割得到后序遍历序列[leftInorder.size,end) ——注意为左闭右开
        int leftPreorderBegin = preorderBegin;
        int leftPreorderEnd = preorderBegin + (deIndex - leftInorderBegin);
        int rightPreorderBegin = preorderBegin + (deIndex - leftInorderBegin);
//        int rightPreorderEnd = preorderBegin; // ?preorderEnd
        int rightPreorderEnd = preorderEnd;

        node->left = buildNode(inorder,leftInorderBegin,leftInorderEnd,preorder,leftPreorderBegin,leftPreorderEnd);
        node->right = buildNode(inorder,rightInorderBegin,rightInorderEnd,preorder,rightPreorderBegin,rightPreorderEnd);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size())
            return nullptr;
        return buildNode(inorder,0,inorder.size(),preorder,0,preorder.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    solution.buildTree(preorder,inorder);
    return 0;
}