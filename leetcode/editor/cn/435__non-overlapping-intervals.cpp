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
    static bool cmp(const vector<int> a, const vector<int> b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 1)
            return 0;
        sort(intervals.begin(),intervals.end(), cmp);
        int res = 1;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
                res++;
            }
        }
        return intervals.size() - res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}