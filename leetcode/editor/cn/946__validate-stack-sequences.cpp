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
//    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//        stack<int> stk;
//        for(int i = 0, j = 0; i < pushed.size();){
//            stk.push (pushed[i++]);
//            while(!stk.empty() && stk.top() == popped[j]){
//                stk.pop();
//                j++;
//            }
//        }
//        return stk.empty();
//    }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int top = 0;    //  用top指针在pushed数组上模拟栈
        int j = 0;  //  popped上的指针
        for(int i = 0;i < pushed.size(); i++){
            pushed[top++] = pushed[i];
            while(top > 0 && pushed[top - 1] == popped[j]){
                top--;
                j++;
            }
        }
        return top == 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    solution.validateStackSequences (pushed,popped);
    return 0;
}