#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 思路为 1 移除多余空格  2 反转整个字符串  3 将每个单词反转
    void removeExtraSpace(string &s){
        int slow = 0,fast = 0;
        // 去除字符串前面的空格
        while(fast < s.size() && s[fast] == ' ')
            fast++;
        // 去掉中间的多余空格
        for(;fast < s.size() - 1; fast++){
            if(s[fast] == ' ' && s[fast + 1] == ' ')
                continue;
            else
                s[slow++] = s[fast];
        }
        if(s[fast] != ' ')
        {
            s[slow] = s[fast];
            s.resize(slow + 1);
        } else
            s.resize(slow );
        // 去掉末尾的多余空格

    }
    void reverseString(string &s,int begin,int end){
        int left = begin, right = end;
        while(left < right)
            swap(s[left++],s[right--]);
    }
    string reverseWords(string &s) {
        removeExtraSpace(s);
        cout<<s<<endl;
        reverseString(s,0,s.size() - 1);
        cout<<s<<endl;
        for(int i = 0;i < s.size();i++){
            int j = i;  // j指针用于寻找每个单词的结尾
            while(j < s.size() && s[j] != ' ')
                j++;
            reverseString(s,i,j - 1);
            i = j;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "  hello world";
    solution.removeExtraSpace(s);
    cout<<s<<"^"<<endl;
//    solution.reverseString(s,0,s.size() - 1);
//    cout<<s;
//    solution.reverseWords(s);
//    cout<<endl<<s;
    return 0;
}