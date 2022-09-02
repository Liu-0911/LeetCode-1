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
        //  超时了
//    int trap(vector<int>& height) {
//        int sum = 0;
//        for (int i = 0; i < height.size(); i++) {
//            // 第一个柱子和最后一个柱子不接雨水
//            if (i == 0 || i == height.size() - 1) continue;
//            int rHeight = height[i]; // 记录右边柱子的最高高度
//            int lHeight = height[i]; // 记录左边柱子的最高高度
//            for (int r = i + 1; r < height.size(); r++) {
//                if (height[r] > rHeight) rHeight = height[r];
//            }
//            for (int l = i - 1; l >= 0; l--) {
//                if (height[l] > lHeight) lHeight = height[l];
//            }
//            int h = min(lHeight, rHeight) - height[i];
//            if (h > 0) sum += h;
//        }
//        return sum;
//    }
    int trap(vector<int> &height){
        if (height.size() <= 2) return 0;
        int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);
        // 记录每个柱子左边柱子最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 记录每个柱子右边柱子最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}