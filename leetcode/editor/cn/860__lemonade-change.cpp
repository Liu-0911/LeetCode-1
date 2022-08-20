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
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        if(bills[0] != 5)
            return false;
        for(int bill : bills){
            if(bill == 5)
                five++;
            else if(bill == 10){
                if(five < 1) return false;
                five--;
                ten++;
            } else{ //  如果收到20美元，优先使用一张10美元和一张5美元找零
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                } else if(five > 2){
                    five -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}