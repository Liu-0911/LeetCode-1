#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<int> bc;
        for(auto n : s){
            if(n == '(')
                bc.push(')');
            else if(n == '[')
                bc.push(']');
            else if(n == '{')
                bc.push('}');
            else if (bc.empty() || bc.top() != n)
                return false;
            else
                bc.pop();
        }
        return bc.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}