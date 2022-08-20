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
    vector<string> res;
    vector<string> tmp;
    void backtracking(string &s,int startIndex){
        if(startIndex == s.size() && tmp.size() == 4){
            string str = "";
            for(auto n : tmp){
                str += n + '.';
            }
            str.pop_back();
            res.emplace_back(str);
            return;
        } else if(startIndex < s.size() && tmp.size() == 4 || startIndex > s.size())
            return;
        for(int i = 1;i <= 3;i++){
            if(i != 1 && s[startIndex] == '0')
                return;
            string str = s.substr(startIndex,i);
            if(i == 3 && atoi(str.c_str()) > 255)
                return;
            tmp.emplace_back(str);
            backtracking(s,startIndex + i);
            tmp.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "abcdefg";
    cout<<s.substr(0,1);
    return 0;
}