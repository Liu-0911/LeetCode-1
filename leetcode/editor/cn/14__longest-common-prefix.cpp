#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <typeinfo>


using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        auto minmax = minmax_element(strs.begin(),strs.end());
        for(int i = 0; i < minmax.first->size(); i++){
            if( (*minmax.first)[i] != (*minmax.second)[i] )
//            if(minmax.first->at(i) != minmax.second->at(i))
                return minmax.first->substr(0,i);
        }
        return *minmax.first;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    // minmax为pair类型，其中minmax.first为指向最小元素的指针，此时*minmax为一个string类型字符串
    // *minmax.first = minmax.first[0]    *minmax.first[0] = minmax.first[0][0] = minmax.fitsr->at(0)
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
//    string resu = solution.longestCommonPrefix(strs);
//    cout<<resu;
    auto minmax = minmax_element(strs.begin(),strs.end());
    cout<<"1 "<<*minmax.first<<endl;
//    cout<<minmax.first[0][0]<<endl<<minmax.first->at(0)<<endl;
    string a = "abcdefg";
    string *stra = &a;
    int a1[10] = {1};
    int * stra1 = a1;
    cout<<"2 "<<(*minmax.first)[0]<<endl;
    cout<<"3 "<<*stra<<endl;
    cout<<"4 "<<stra->at(0)<<endl;
    return 0;

}