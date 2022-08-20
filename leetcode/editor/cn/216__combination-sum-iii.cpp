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
    void backtracking(int k,int n,int sum,int startIndex){
        if(path.size() == k){
            if(sum == n)
                res.emplace_back(path);
            return;
        }
        for(int i = startIndex;i < 10;i++){
            sum += i;
            path.emplace_back(i);
            backtracking(k,n,sum,i + 1);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>>combinationSum3(int k, int n) {
        backtracking(k,n,0,1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}