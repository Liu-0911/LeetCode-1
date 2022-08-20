#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  // 左指针初始在最左（最小值），右指针初始为最右（最大值），
        // 先对数组排序                                       然后计算两数和，若和小于tar，则让左指针右移（变大），反之右指针左移
//        sort(nums.begin(), nums.end());
        // 左右指针
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            // 根据 sum 和 target 的比较，移动左右指针
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else if (sum == target) {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}