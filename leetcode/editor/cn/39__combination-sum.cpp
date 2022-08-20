#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backstracking(vector<int>& candidates,int target,int sum,int startIndex){
        if(sum == target){
            res.emplace_back(path);
            return;
        } else if(sum > target)
            return;
        for(int i = startIndex;i < candidates.size();i++){
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            backstracking(candidates,target,sum,i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backstracking(candidates,target,0,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}