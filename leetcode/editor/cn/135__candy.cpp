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
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        //  从左往右遍历 处理右边大于左边的情况
        for(int i = 1; i < ratings.size(); i++)
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        //  从右往左遍历 处理左边大于右边的情况  ！！如果从左往右遍历，那么上一次比较的结果将无法往下传递
        for(int i = ratings.size() - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                candy[i] = max(candy[i],candy[i + 1] + 1);
        int res = 0;
        for(auto n : candy)
            res += n;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}