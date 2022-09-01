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
    //  ѭ��������Բ�ȡƴ������ԭ����ķ�ʽʵ�֣�Ҳ���Բ�ȡ��������ԭ����ʵ��
    //  �����ȡ�ڶ��֣�ʱ��Ϳռ临�Ӷȸ�С��
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if (nums.size() == 0) return res;
        stack<int> st;
        for(int i = 0; i< nums.size() * 2; i++){
            //  ģ���������ԭ���飬ע�ⶼ����i % nums.size()������
            while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push (i % nums.size());
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}