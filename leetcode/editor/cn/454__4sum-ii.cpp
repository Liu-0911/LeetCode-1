#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // HashMap 存一个数组，如 A。然后计算三个数组之和，如 BCD。时间复杂度为：O(n)+O(n^3)，得到 O(n^3).
    //HashMap 存三个数组之和，如 ABC。然后计算一个数组，如 D。时间复杂度为：O(n^3)+O(n)，得到 O(n^3).
    //HashMap存两个数组之和，如AB。然后计算两个数组之和，如 CD。时间复杂度为：O(n^2)+O(n^2)，得到 O(n^2)
    // 所以采用最后一种 ，将A B数组的和sumAB和出现的次数存入hashmap
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;// key为sumAB value为sunAB出现的次数
        int count = 0;
        for(auto a : nums1)
            for(auto b : nums2){
                map[a + b]++;
            }
        for(auto c : nums3)
            for (auto d : nums4) {
                if(map.find(0 - (c + d)) != map.end())
                    count += map[0 - (c + d)];
            }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}