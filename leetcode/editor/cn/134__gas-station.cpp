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
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int spare = 0;  //  ʣ�������
//        int minSpare = INT32_MAX;   //  ��¼ʣ��������С���±꣬��Ϊ��]
//        int minIndex = 0;
//        for(int i = 0; i < gas.size(); i++){
//            spare += gas[i] - cost[i];
//            if(spare < minSpare){
//                minSpare = spare;
//                minIndex = i;
//            }
//        }
//        return spare < 0 ? -1 : (minIndex + 1) % gas.size();
//    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // ��ǰ�ۼ�rest[i]�� curSumһ��С��0
                start = i + 1;  // ��ʼλ�ø���Ϊi+1
                curSum = 0;     // curSum��0��ʼ
            }
        }
        if (totalSum < 0) return -1; // ˵����ô�߶���������һȦ��
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}