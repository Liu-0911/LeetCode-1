#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        if(s == " ")
            return 1;
//        unordered_set<char> set;
        int numOfChar[100] = {0};
        int fast = 0, low = 0;
        int maxOfString = 0;
//        for(;fast < s.size();fast++){
//            while(set.find(s[fast]) != set.end()){
//                set.erase(s[low++]);
//            }
//            maxOfString = max(maxOfString,fast - low + 1);
//            set.insert(s[fast]);
//        }
        for(;fast < s.size();fast++){
            while(numOfChar[s[fast]- ' ' ] == 1){
                numOfChar[s[low]- ' ' ] -= 1;
                low++;
            }
            maxOfString = max(maxOfString,fast - low + 1);
            numOfChar[s[fast]- ' ' ] += 1;
        }
        return maxOfString;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = " ";
    cout<<' ' + 0<<endl;
    cout<<'a' + 0<<endl;
    cout<<solution.lengthOfLongestSubstring(s);
    return 0;
}