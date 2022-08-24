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
    //dp[0]Ϊ��͵��ǰ�ڵ㣬dp[1]Ϊ͵��ǰ�ڵ�
private:
    vector<int> robTree(TreeNode *cur){
        if(cur == nullptr)
            return {0,0};
        //  ����Ҫ���к����������Ϊ��Ҫ���ӽ��Ľ��
        vector<int> left = robTree((cur->left));
        vector<int> right = robTree((cur->right));
        //  ͵��ǰ���
        int val1 = cur->val + left[0] + right[0];
        //  ��͵��ǰ�ڵ� �����͵���ӽ�㣨͵��͵����ȡ������һ��ֵ��
        int val2 = max(left[0],left[1]) + max(right[0],right[1]);
//        int val2 = left[1] + right[1];    �п���͵���ӽ��Ľ��С�ڲ�͵���ӽ�㣬�����Ҫ�ж�
        return {val2,val1};
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0],res[1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}