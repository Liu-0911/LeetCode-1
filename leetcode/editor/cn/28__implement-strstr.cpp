#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void buildNext(int *next,const string s){
        int lenPrefix = 0; // 当前共同前后缀长度
        next[0] = 0;
        for(int i = 1; i < s.size();) {
           if(s[lenPrefix] == s[i]){
               lenPrefix++;
               next[i] = lenPrefix;
               i++;
           } else{
               if(lenPrefix == 0)
                   next[i++] = 0;
               else{
                   lenPrefix = next[lenPrefix - 1];
               }
           }
        }
    }
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int next[needle.size()];
        buildNext(next,needle);
        for(auto n : next){
            cout<<n<<" ";
        }
        cout<<endl;
        int i = 0,j = 0;   // i为主串中的指针，j为模式串中的指针
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else if(j > 0){
                j = next[j - 1];
            } else
                i++;
            if(j == needle.size())
                return i - j;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string haystack = "aaaaa", needle = "abaabcac";
//    solution.strStr(haystack,needle);
    int next[needle.size()];
    solution.buildNext(next,needle);
    for(auto n : next){
        cout<<n<<" ";
    }
    cout<<endl;
    solution.getNext(next,needle);
    for(auto n : next){
        cout<<n<<" ";
    }
    return 0;
}