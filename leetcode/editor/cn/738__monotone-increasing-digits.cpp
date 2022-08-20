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
    int monotoneIncreasingDigits(int n) {   //  �Ӻ���ǰ����������num����洢ÿһλ
        string num = to_string(n);
        int len = num.size();
//        for(int i = len - 1; i > 0; i--){
//            if(num[i - 1] > num[i]){
//                num[i - 1]--;
//                num[i] = '9';
//            }
//        }
        for(int i = len - 1; i > 0; i--){   //  ��flag���9����һλ��ʼ
            if(num[i - 1] > num[i]){
                num[i - 1]--;
                len = i;
            }
        }
        for(int i = len; i < num.size();i++){
            num[i] = '9';
        }
        return stoi(num);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    solution.monotoneIncreasingDigits(100);
    return 0;
}