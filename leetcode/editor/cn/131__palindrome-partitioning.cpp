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
private:
    vector<vector<string>> res;
    vector<string> path;
    bool isPalind(const string& s,int start,int end){
        for(int i = start,j = end;i < j; i++,j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    void backtracking(const string &s,int startIndex) {
        if (startIndex >= s.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalind(s, startIndex, i)) {   //  是回文串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.emplace_back(str);
            } else  //  不是回文串则跳过
                continue;
            backtracking(s, i + 1);  //  寻找i+1位置的回文字串
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}