#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty() || nums.size() < 4)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            // 剪枝操作——去掉不必要的操作
            // 如果当前最小的四个数加起来都大于tar 直接break
            if( (long long ) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target )   // !!!!!注意使用longlong 测试数据中有很大的数据，int可能会越界
                break;
            // 如果当前值加上最大的三个数加起来都小于tar 直接break
            if( (long long )nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
                continue;   // ！！！！这里不能直接break 因为随着i++ nums[i]也会变大
            for(int j = i + 1;j < nums.size()-2;j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                if( (long long )nums[i] + nums[j] + nums[j+1] + nums[j+2] > target )
                    break;
                // 如果当前值加上最大的三个数加起来都小于tar 直接break
                if( (long long )nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                    continue;  // ！！！！这里不能直接break 因为随着i++和j++ nums[i] + nums[j]也会变大
                // 开始双指针
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    long long int sum = nums[i] + nums[j] +nums[left] +nums[right];
                    if(sum == target){
                        res.emplace_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});

                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if(sum > target){
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        right--;
                    } else{
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}