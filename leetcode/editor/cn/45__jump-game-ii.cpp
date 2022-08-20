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
    int jump(vector<int>& nums) {
        int curDistance = 0;    //  ������ʾ��һ�����ܵ������Զ��Χ���������ʱ�±����������룬��˵����Ҫ����һ��
        int nextDistance = 0;   //  ������ʾ��һ�����ܴﵽ����Զ��Χ
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            nextDistance = max(nums[i] + i, nextDistance);
            if(i == curDistance){
                curDistance = nextDistance;
                res++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}