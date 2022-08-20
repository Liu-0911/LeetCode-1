#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--;
        n--;
        while(n >= 0){
            while(m >= 0 && nums1[m] > nums2[n])
                swap(nums1[i--],nums1[m--]);
            swap(nums1[i--] , nums2[n--]);
        }
    }
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//       for(int i = m, j=0;i < nums1.size(); i++,j++)
//           nums1[i] = nums2[j];
//       sort(nums1.begin(),nums1.end());
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}