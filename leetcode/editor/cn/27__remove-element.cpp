#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0; //删除元素后新数组的值
        int slow = 0; //删除元素后新数组的值对应的下标
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> nums = {2,1,2,2,3,0,4,2};
    auto num = solution.removeElement(nums,2);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    cout<<num;
    return 0;
}