#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charnum[26] = {0};
        for(auto n : magazine){
            charnum[n - 'a']++;
        }
        for(auto n : ransomNote){
            charnum[n - 'a']--;
        }
        for(auto n : charnum){
            if(n < 0)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}