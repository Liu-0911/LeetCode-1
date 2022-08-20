#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 三数之和即使用三个指针，除去左右指针外，使用一个新指针遍历排序后的数组，然后让left指针从新指针的左边开始，剩下的思路相当于双指针寻找tar = 0 - nums[i]；
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        if(nums.size() < 3)
            return {};
        for(int i = 0;i < nums.size() - 2;i++){
//            if(nums[i] > 0)    // 因为是排序后的数组，如果nums[i]>0，则后面不可能有<0的数，直接返回
//                return res;
            if(i>0 && nums[i] == nums[i-1])  // 防止三元组重复，相同的元素只遍历一次
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] > 0)
                break;
            if(nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0)
                continue;
            int left = i + 1,right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if(sum > 0){
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                } else{
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                }
            }
        }
//        cout<<" ";
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = solution.threeSum(nums);
    for(auto i : res){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
//    cout<<res;
    return 0;
}