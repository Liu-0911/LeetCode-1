#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int fast=0,slow = 0; // fast为新数组的元素，slow为新数组元素对应的下标
        // fast = 1;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {

                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,2,2,2,3,4};
    auto num = solution.removeDuplicates(nums);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    cout<<num;
    return 0;
}