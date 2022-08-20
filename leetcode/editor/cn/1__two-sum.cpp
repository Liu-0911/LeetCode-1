#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 使用hashmap
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int,int>map;  // map中存储的形式为<数值，下标>
//        for(int i = 0; i < nums.size(); i++){
//            auto iter = map.find(target - nums[i]);
//            if(iter != map.end()){
//                return {i, iter->second};
//            }
//            map.insert(pair<int, int>(nums[i], i));
//        }
//        return {};
//    }

    // 使用双指针
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp = nums;
//         先对数组排序
        sort(tmp.begin(), tmp.end());
        // 左右指针
        int left = 0, right = tmp.size() - 1;
        while (left < right) {
            int sum = tmp[left] + tmp[right];
            // 根据 sum 和 target 的比较，移动左右指针
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else if (sum == target) {
                break;
            }
        }
        if(left < right){ // 说明找到了答案
            int i = 0,j = 0;
            for(i = 0; i < nums.size(); i++){
                if(nums[i] == tmp[left])
                    break;
            }
            for(j = 0; j < nums.size(); j++){
                if(nums[j] == tmp[right] && j != i)
                    break;
            }
            return {i,j};
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {2,7,11,15};
    solution.twoSum(nums,9);
    return 0;
}