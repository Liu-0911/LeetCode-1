#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //��һ���������鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
    //�ڶ�������ǰ���������������������Ϊ������ͬʱK--
    //�����������K������0����ô����ת����ֵ��С��Ԫ�أ���K����
    //���Ĳ������
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i = 0; i < nums.size(); i++){
            if(k > 0 && nums[i] < 0){
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2 == 1)
            nums[nums.size() - 1] *= -1;
        int res = 0;
        for(auto n : nums)
            res += n;
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}