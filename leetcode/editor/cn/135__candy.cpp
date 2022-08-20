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
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        //  �������ұ��� �����ұߴ�����ߵ����
        for(int i = 1; i < ratings.size(); i++)
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        //  ����������� ������ߴ����ұߵ����  ��������������ұ�������ô��һ�αȽϵĽ�����޷����´���
        for(int i = ratings.size() - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                candy[i] = max(candy[i],candy[i + 1] + 1);
        int res = 0;
        for(auto n : candy)
            res += n;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}