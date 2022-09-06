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
    // TODO https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/tong-ji-zi-chuan-zhong-de-wei-yi-zi-fu-b-ajio/
public:
    int uniqueLetterString(string s) {
        //存储last字符前一个字符所在位置
        vector<int> lastIndexMap(26,-1);
        //存储cur字符当前所处位置
        vector<int> curIndexMap(26,-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            //next字符
            int index = s[i] - 'A';
            //cur字符的索引不是-1，计算cur字符的贡献值(处理字符串中有重复字符的情况)
            if (curIndexMap[index] > -1) {
                ans += (i - curIndexMap[index]) * (curIndexMap[index] - lastIndexMap[index]);
            }
            //滚动存放cur和last
            lastIndexMap[index] = curIndexMap[index];
            curIndexMap[index] = i;
        }
//        计算最后next字符的贡献值
        for (int i = 0; i < 26; i++) {
            if (curIndexMap[i] > -1) {
                ans += (curIndexMap[i] - lastIndexMap[i]) * (s.size() - curIndexMap[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}