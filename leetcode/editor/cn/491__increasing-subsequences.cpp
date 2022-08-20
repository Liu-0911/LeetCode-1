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

    void backtracking(vector<int>& nums,int startIndex){
        if(path.size() > 1)
            res.emplace_back(path);
//        unordered_set<int> used;    //  每一层的set都只负责记录本层结点时候已经被用过
        int used[201] = {0};
        for(int i = startIndex;i < nums.size();i++){
            if((!path.empty() && nums[i] < path.back())     //  如果当前元素不能构成递增序列 跳过
               || used[nums[i] + 100] != 0)    //  如果当前元素已经用过 跳过
                continue;
            used[nums[i]+ 100] = 1;
            path.emplace_back(nums[i]);
            backtracking(nums,i + 1);
            path.pop_back();    //  这里used数组没有恢复状态的原因是新的一层的set会被重新定义，每个set只负责本层
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}