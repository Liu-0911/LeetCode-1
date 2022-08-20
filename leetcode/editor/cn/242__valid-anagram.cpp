#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int charnum[26] = {0};
        for(auto n : s){
            charnum[n - 'a']++;
        }
        for(auto n : t){
            charnum[n - 'a']--;
        }
        for(auto n : charnum){
            if(n != 0)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}