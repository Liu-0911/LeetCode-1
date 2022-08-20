#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
//    void moveZeroes(vector<int>& nums) {
//        int p = removeElement(nums,0);
//        for(; p < nums.size(); p++){
//            nums[p] = 0;
//        }
//    }

    // 双指针法
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
//        for(int fast : nums){
        for(; fast < nums.size();fast++){
            if(nums[fast]){
                swap(nums[fast],nums[slow]);
                slow++;
            }
        }
//        for (int n: nums) {
//            if (n) {
//                swap(n, nums[slow]);   // 这样错误，swap交换了n和nums[slow]的值，但是n的值并不会改变nums[fast]的值
//                slow++;
//            }
//        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    solution.moveZeroes(nums);
    return 0;
}