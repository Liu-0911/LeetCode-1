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
    //  单调栈
    //  单调递增栈（严格递增）
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices);
        stack<int> st;
        for(int i = 0; i < prices.size(); i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                res[st.top()] = res[st.top()] - prices[i];
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