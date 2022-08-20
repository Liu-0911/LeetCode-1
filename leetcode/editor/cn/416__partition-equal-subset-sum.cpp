#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include <numeric>
#include "set"
#include "bitset"
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
//    bool canPartition(vector<int>& nums) {
//        int sum = accumulate(nums.begin(),nums.end(),0);
////        if(sum % 2 == 1)
//        if(sum&1)   //  用&判断奇偶更快
//            return false;
//        sum /= 2;
//        //  dp[j]表示背包总容量是j，最大可以凑成j的子集总和为dp[j]。
//        vector<int> dp(10001,0);
//        for(int i = 0; i < nums.size(); i++){   //  遍历每一个元素
//            for(int j = sum; j >= nums[i]; j--){    //  倒叙遍历容量
//                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//            }
//        }
//        return dp[sum] == sum;
//    }
    //  利用位移实现
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)   //  用&判断奇偶更快
            return false;
        bitset<10001> bits(1);
        for(const auto &num : nums){
            bits |= bits << num;
        }
        return bits[sum >> 1];

    }
//    bool canPartition(vector<int>& nums) {
//        int sum = accumulate(nums.begin(),nums.end(),0);
//        if(sum&1)
//            return false;
//        sum /= 2;
//        set<int> s;
//        for(auto num : nums){
//            set<int> tmp;
//            if(num == sum)
//                return true;
//            else if(num < sum)
//                tmp.emplace(num);
//            for(auto sum_ : s){
//                int res = sum_ + num;
//                if(res == sum)
//                    return true;
//                else if(res < sum)
//                    tmp.emplace(res);
//            }
//            for(auto n : tmp)
//                s.emplace(n);
//        }
//        return false;
//}
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}