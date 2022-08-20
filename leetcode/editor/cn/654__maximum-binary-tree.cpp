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
    //  在区间[begin,end)上建立
    TreeNode* bulidNode(vector<int> &nums,int begin,int end){
        if(begin >= end)
            return nullptr;
        if(begin + 1 == end)
            return new TreeNode(nums[begin]);
        int maxNodeIndex = begin;
        for(int i  = begin + 1;i < end;i++){
            if(nums[i] > nums[maxNodeIndex]) maxNodeIndex = i;
        }
        TreeNode* node = new TreeNode(nums[maxNodeIndex]);

        node->left = bulidNode(nums,begin,maxNodeIndex);
        node->right = bulidNode(nums,maxNodeIndex + 1,end);

        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return bulidNode(nums,0,nums.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}