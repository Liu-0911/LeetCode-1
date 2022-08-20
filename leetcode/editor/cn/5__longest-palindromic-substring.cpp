#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 双指针中心扩散法--每遍历一个字符，从这个字符开始向两边扩散寻找回文子串
    string findsubstr(string s,int left,int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right - 1 - ( left + 1 ) + 1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0;i < s.size();i++){
            string s1 = findsubstr(s,i,i);
            string s2 = findsubstr(s,i,i+1);
            string maxs = s1.size() > s2.size() ? s1 : s2;
            res = maxs.size() > res.size() ? maxs : res;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}