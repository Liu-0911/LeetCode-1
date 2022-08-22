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
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){   //  ������������
            for(int j = 0; j < nums.size(); j++){  //  ������Ʒ
                if(i - nums[j] >= 0 &&  dp[i] < INT_MAX - dp[i - nums[j]])  //  ��һ����Ϊ�˷�ֹC++ �е�int��������Ӷ��׳��쳣
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}