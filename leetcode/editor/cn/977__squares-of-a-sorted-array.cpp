#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    暴力法:平方后排序
//    vector<int> sortedSquares(vector<int>& nums) {
//        for(int i=0;i<nums.size();i++) {
//            nums[i] *= nums[i];
//        }
//        sort(nums.begin(),nums.end());
//        return nums;
//    }
//    双指针法：两个指针分别指向开头和结尾，每次两个指针中较大的移动到新数组
//    vector<int> sortedSquares(vector<int>& nums) {
//        int i=0,j=nums.size()-1;
//        int k=j; // 因为最后要升序排列，所以从数组尾部开始赋值
//        vector<int> result(nums.size(),0);
//        for(;i<=j;){
//            if(nums[i] * nums[i] > nums[j] * nums[j]){
//                result[k--] = nums[i] * nums[i];
//                i++;
//            } else{
//                result[k--] = nums[j] * nums[j];
//                j--;
//            }
//        }
//        return result;
//    双指针法优化：左指针取负值和右指针比较即可，不需要平方后比较
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int k = j; // 因为最后要升序排列，所以从数组尾部开始赋值
        vector<int> result(nums.size(), 0);
        while (i <= j) {
            if (-nums[i] > nums[j]) {
                result[k--] = nums[i] * nums[i];
                i++;
            } else {
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    vector<int> nums = {0,1,9,16,100};
    Solution s;
    auto resu = s.sortedSquares(nums);
    for(auto n:resu){
        cout<<n<<" ";
    }
    return 0;
}