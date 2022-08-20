#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    string minWindow(string s, string t) {
//        unordered_map<char,int> hs, ht;
//        for(auto n: t){   // 创建t字符串的哈希表
//            ht[n]++;
//        }
//        int head = 0, tail = 0; // 滑动区间为[tail,head]
//        int subStringLength = 0;
//        string subString = "";
//        for(;head < s.size();head++){
//            if(hs[s[head]] < ht[s[head]])  // 如果hs[s[head]] < ht[s[head]]表明当前加入的字符是必须的，没有达到字符串t所需要的数量
//                subStringLength++;
//            hs[s[head]]++;  // head++即head指针向后移，对应的哈希表中的值要+1
//            while(hs[s[tail]] > ht[s[tail]]) // 当hs[s[tail]] > ht[s[tail]]表明需要收缩滑动窗口的大小，直到收缩到最小为止
//                hs[s[tail++]]--;
//            if(subStringLength == t.size()){ // 如果字串的长度和字符串t的长度相同，则表明当前字串符合要求
//                if(subString.empty() || (head - tail + 1) < subString.size()){
//                    subString = s.substr(tail, head - tail + 1);
//                }
//            }
//        }
//        return subString;
//    }
//    执行耗时:24 ms,击败了47.62% 的C++用户
//    内存消耗:8.1 MB,击败了26.28% 的C++用户


    // 优化后的版本
    // 将hs与ht两个哈希表合并为一个数组hash，核心优化思路就是利用数组的每一位来存储字符串中各个字符的数量
    string minWindow(string s, string t) {
        int hash[128] = {0};
        for(auto n: t){   // 遍历字符串t时将对应的hash数组那一位的数字-1，用来存储t中每个字符的数量
            hash[n]--;
        }
        int head = 0, tail = 0; // 滑动区间为[tail,head]
        int subStringLength = 0;
        string subString = "";
        for(;head < s.size();head++){
            if(hash[s[head]] < 0)  // 如果hash[s[head]]表明当前加入的字符是必须的，没有达到字符串t所需要的数量
                subStringLength++;
            hash[s[head]]++;  // head++即head指针向后移，对应的数组的值要+1
            while(hash[s[tail]] > 0) // 当hs[s[tail]] > ht[s[tail]]表明需要收缩滑动窗口的大小，直到收缩到最小为止
                hash[s[tail++]]--;
            if(subStringLength == t.size()){ // 如果字串的长度和字符串t的长度相同，则表明当前字串符合要求
                if(subString.empty() || (head - tail + 1) < subString.size()){
                    subString = s.substr(tail, head - tail + 1);
                }
            }
        }
        return subString;
    }
//    执行耗时:4 ms,击败了98.79% 的C++用户
//    内存消耗:7.7 MB,击败了45.88% 的C++用户
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<solution.minWindow(s,t)<<endl;
    cout<<"Over!"<<endl;
    return 0;
}