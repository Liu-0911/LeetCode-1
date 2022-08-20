#include<vector>
#include<iostream>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 滑动区间——让区间尾部不停后裔，区间头部动态移动，即当区间内的总和
    // tail ****** head
    int minSubArrayLen(int target, vector<int>& nums, vector<int>& result) {
        int head=0,tail =0;
        int num=0;
        int minNum = INT32_MAX;
        for(;head<nums.size();head++){
            num += nums[head];
            while(num >= target){
                minNum = (head - tail + 1) < minNum ? (head - tail + 1) : minNum;
                num -= nums[tail++];
            }
        }
        result[0] = minNum ==INT32_MAX ? 0 : minNum;
        result[1] = head ;
        result[2] = tail ;
        return minNum ==INT32_MAX ? 0 : minNum;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int head=0,tail =0;
        int num=0;
        int minNum = INT32_MAX;
        for(;head<nums.size();head++){
            num += nums[head];
            while(num >= target){
                minNum = (head - tail + 1) < minNum ? (head - tail + 1) : minNum;
                num -= nums[tail++];
            }
        }
        return minNum ==INT32_MAX ? 0 : minNum;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
    Solution s;
    vector<int> result(3,0);
    s.minSubArrayLen(15,nums,result);
    for(auto n:result){
        cout<<n<<" ";
    }
    return 0;
}