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
//    int maxProfit(vector<int>& prices) {
//        int proFit = 0;
//        for(int i = 0;i < prices.size() - 1; i++){
//            int tmp = prices[i] - prices[i + 1];
//            if(tmp < 0)
//                proFit += tmp;
//        }
//        return -proFit;
//    }
    int maxProfit(vector<int>& prices) {
        int proFit = 0;
        for(int i = 0;i < prices.size() - 1; i++){
            int tmp = prices[i + 1] - prices[i];
            if(tmp > 0)
                proFit += tmp;
        }
        return proFit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}