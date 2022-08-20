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
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n,int k,int startIndex){
        if(path.size() == k){
            res.emplace_back(path);
            return;
        }
//        for(int i = startIndex;i <= n;i++){
//            path.emplace_back(i);
//            backtracking(n,k,i+1);
//            path.pop_back();
//        }
        //  减枝优化
        for(int i = startIndex;i <= n - (k - path.size()) + 1;i++){
            path.emplace_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}