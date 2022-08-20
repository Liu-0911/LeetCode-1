#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//leetcode submit region begin(Prohibit modification and deletion)


class Solution {
public:
    // 非递归版
//    vector<vector<int>> levelOrder(Node* root) {
//        queue<Node*> que;
//        if(root != nullptr) que.push(root);
//        vector<vector<int>> res;
//        while(!que.empty()){
//            int numOfNode = que.size();
//            vector<int> layer;
//            for(int i = 0;i < numOfNode;i++){
//                Node* node = que.front();
//                que.pop();
//                layer.emplace_back(node->val);
//                for(int j = 0;j < node->children.size();j++)
//                    if(node->children[j])
//                        que.push(node->children[j]);
//            }
//            res.emplace_back(layer);
//        }
//     return res;
//    }

    // 递归版
    void dfs(Node *cur,vector<vector<int>> &res,int depth){
        if(cur == nullptr)
            return;
        if(res.size() == depth){
            res.emplace_back(vector<int>{});
        }
        res[depth].emplace_back(cur->val);
        for(int i = 0;i < cur->children.size();i++){
            dfs(cur->children[i],res,depth + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root)  {
        vector<vector<int>> res;
        int depth = 0;
        dfs(root,res,depth);
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}