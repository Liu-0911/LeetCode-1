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
    //  �����������л�����ַ����ռ临�Ӷ�̫�ߣ����Ը�ÿһ������һ��Ψһ�ı������ʾ�����ٿռ临�Ӷ�
    // ���
    vector<TreeNode *> res;
    // �����ַ��� �� Ψһ��� ��ӳ��
    unordered_map<string, int> str2index;
    // Ψһ��� �� ���� ��ӳ��
    unordered_map<int, int> index2cnt;
    // �����ı�ţ���1��ʼ����0��ʾ����Ч��������������֤Ψһ
    int index = 1;
    // ���ص�ǰ�ڵ������ı��
    int dfs ( TreeNode *root ) {
        if ( root == nullptr ) return {};
        string str = to_string ( root->val ) + "," + to_string ( dfs ( root->left ) ) + "," + to_string ( dfs ( root->right ) );
        if ( str2index.find ( str ) == str2index.end () )//  û�ҵ�
        {
            str2index[ str ] = index;
            index++;
        }
        int tmp = str2index[ str ];
        index2cnt[ tmp ]++;
        // �״η����ظ������ӽ����
        if ( index2cnt[ tmp ] == 2 ) {
            res.emplace_back ( root );
        }
        return tmp;
    }
//    string dfs(TreeNode * root,vector<TreeNode*> &res, unordered_map<string, int>& mp ){
//        if(root==0) return {};
//        //�������������л�
//        string str = to_string(root->val) + "," + dfs(root->left, res, mp) + "," + dfs(root->right, res, mp);
//        if(mp[str] == 1){
//            res.emplace_back (root);
//
//        }
//        mp[str]++;
//        return str;
//    }
public:
    //  ���л�ÿһ������
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