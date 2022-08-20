#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getNumOfRoma(char c){
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        int curnum = 0,nextnum = 0;
        for(int i = 0;i < s.size() - 1;i++){
            curnum = getNumOfRoma(s[i]);
            nextnum = getNumOfRoma(s[i+1]);
            if(curnum >= nextnum){
                sum += curnum;
            } else{
                sum -= curnum;
            }
        }
        sum += getNumOfRoma(s[s.size() - 1]);

        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}