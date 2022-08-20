#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
     /*------使用栈-------------------*/
//    string removeDuplicates(string s) {
//        stack<char> stk;
//        for(auto c : s){
//            if( stk.empty()||c != stk.top() )
////            if(c != stk.top() || stk.empty())   // 这样先调用stk.top在初始栈为空时会报错
//                stk.push(c);
//            else
//                stk.pop();
//        }
//        string res = "";
//        while(!stk.empty()){
//            res += stk.top();
//            stk.pop();
//        }
//        reverse(res.begin(),res.end());
//        return res;
//    }


    /*------直接操作字符串-------------------*/
        string removeDuplicates(string S) {
            int cnt = 0;
            for (auto& ch : S) {
                if (cnt == 0 || ch != S[cnt - 1]) S[cnt++] = ch;
                else cnt--;
            }
            S.resize(cnt);
            return S;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "abbaca";
    cout<<solution.removeDuplicates(s);
    return 0;
}