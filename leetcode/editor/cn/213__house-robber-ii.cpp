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
    //  �����198��ҽ������Ŀ������ͬ��Ψһ��ͬ�����������˻�����ͷ��βֻ��͵һ��
    //  ���Ƿ���������ֱ���㣬���ȥ��������ֵ
private:
    //  198����߼� ��������Ϊ[begin,end]
    int robb(vector<int>& nums,int begin,int end) {
        if(begin == end)
            return nums[begin];
        vector<int> dp(nums.size() + 1, 0);
        dp[begin] = nums[begin];
        dp[begin + 1] = max(nums[begin],nums[begin + 1]);
        for(int i = begin + 2; i <= end; i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int res1 = robb(nums,0,nums.size() - 2);    //  ��͵ͷ
        int res2 = robb(nums,1,nums.size() - 1);    //  ��͵β
        return max(res1,res2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}