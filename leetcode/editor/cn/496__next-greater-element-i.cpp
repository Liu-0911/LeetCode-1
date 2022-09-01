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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        if (nums1.size() == 0) return res;
        unordered_map<int, int> umap; // 用map实现nums1中数值和下标的映射
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                if(umap.count (nums2[st.top()]) > 0){   //  如果map里保存了这个数
                    int index = umap[nums2[st.top()]];
                    res[index] = nums2[i];
                }
                st.pop();
            }
            st.push (i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}