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

    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = INT32_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice)    //  �����ǰ�۸�С����С�۸��൱������һֻ�µĹ�Ʊ
                minPrice = prices[i];
            else if(prices[i] > minPrice + fee){    //  �����ǰ�۸�����������ۼ������ѣ�����������������
                res += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;    //  ����������һ֧��Ʊʱ�����Ǿ��������������ͬ�۸����������������һ֧��Ʊ��Ȩ�����������Կ��ǵ������Ǽ۵����
            } else{ //  ����۸�����С�۸���С�۸��������֮���򲻽��в���
                continue;
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