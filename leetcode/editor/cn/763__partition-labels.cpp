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
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for(int i = 0; i < s.size(); i++){  //  记录每个字母出现的最后位置
            hash[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){  //  记录每个字母出现的最后位置
            end = max(end,hash[s[i] - 'a']);
            if(i == end){
                res.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}