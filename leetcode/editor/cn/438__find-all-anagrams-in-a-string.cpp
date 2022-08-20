#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    执行耗时:8 ms,击败了91.43% 的C++用户
//    内存消耗:8.4 MB,击败了83.42% 的C++用户
//    vector<int> findAnagrams(string s, string p) {
//        int fast = 0, slow = 0;
//        vector<int> res;
//        int tarnum[26] = {0}, curnum[26] = {0};  // 用于记录目标字串中各个字符的个数
//        for(auto n : p){
//            tarnum[n - 'a']++;
//        }
//        while(fast < s.size()){
//            curnum[s[fast] - 'a']++;
//            while(curnum[s[fast] - 'a'] > tarnum[s[fast] - 'a']){
//                curnum[s[slow] - 'a']--;
//                slow++;
//            }
//            if(fast - slow + 1 == p.size())
//                res.emplace_back(slow);
//            fast++;
//        }
//        return  res;
//    }

    // 优化版本 将tarnum和curnum合并
    vector<int> findAnagrams(string s, string p) {
        int fast = 0, slow = 0;
        vector<int> res;
        int tarnum[26] = {0};  // 用于记录目标字串中各个字符的个数
        for(auto n : p){
            tarnum[n - 'a']++;
        }
        while(fast < s.size()){
            tarnum[s[fast] - 'a']--;
            while(tarnum[s[fast] - 'a'] < 0){
                tarnum[s[slow] - 'a']++;
                slow++;
            }
            if(fast - slow + 1 == p.size())
                res.emplace_back(slow);
            fast++;
        }
        return  res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "cbaebabacd", p = "abc";
    auto res = solution.findAnagrams(s,p);
    for(auto n : res)
        cout<<n<<" ";
    return 0;
}