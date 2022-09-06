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
    // TODO https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/tong-ji-zi-chuan-zhong-de-wei-yi-zi-fu-b-ajio/
public:
    int uniqueLetterString(string s) {
        //�洢last�ַ�ǰһ���ַ�����λ��
        vector<int> lastIndexMap(26,-1);
        //�洢cur�ַ���ǰ����λ��
        vector<int> curIndexMap(26,-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            //next�ַ�
            int index = s[i] - 'A';
            //cur�ַ�����������-1������cur�ַ��Ĺ���ֵ(�����ַ��������ظ��ַ������)
            if (curIndexMap[index] > -1) {
                ans += (i - curIndexMap[index]) * (curIndexMap[index] - lastIndexMap[index]);
            }
            //�������cur��last
            lastIndexMap[index] = curIndexMap[index];
            curIndexMap[index] = i;
        }
//        �������next�ַ��Ĺ���ֵ
        for (int i = 0; i < 26; i++) {
            if (curIndexMap[i] > -1) {
                ans += (curIndexMap[i] - lastIndexMap[i]) * (s.size() - curIndexMap[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}