#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > result)
                result = count;
            if(count <= 0)
                count = 0;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}