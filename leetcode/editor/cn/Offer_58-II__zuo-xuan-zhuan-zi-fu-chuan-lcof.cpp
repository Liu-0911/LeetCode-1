#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //                          abcdefg
    // 1 反转区间为前n的子串      bacdefg
    // 2 反转区间为n到末尾的子串   bagfedc
    // 3 反转整个字符串           cdefgab
    string reverseLeftWords(string &s, int n) {
        reverse(s.begin(),s.begin() + n);
        reverse(s.begin() + n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}