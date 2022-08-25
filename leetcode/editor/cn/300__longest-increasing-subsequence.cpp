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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        vector<int> dp(nums.size(),1);  //  �����еĳ�����СΪ1��dp[i]��ʾi֮ǰ����i����nums[i]��β����������еĳ���
        int res = 1;
        for(int i = 0; i < nums.size(); i++){   //  ��������
            for(int j = 0; j < i; j++){ //  ʹ��j����0��i-1��ȡdp[j] + 1�����ֵ
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);  //ע�����ﲻ��Ҫdp[i] �� dp[j] + 1���бȽϣ���������Ҫȡdp[j] + 1�����ֵ��
            }
            res = res > dp[i] ? res : dp[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}