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
    //  ͨ����һά���飬ҪѰ����һ��Ԫ�ص��ұ߻�����ߵ�һ�����Լ������С��Ԫ�ص�λ�ã���ʱ���Ǿ�Ҫ�뵽�����õ���ջ�ˡ�
    //  ����Ϊ�����ݼ�ջ
    //  �����������飬���ջ���գ��ҵ�ǰ���ִ���ջ��Ԫ�أ���ô���ֱ����ջ�Ļ��Ͳ��� �ݼ�ջ ��������Ҫȡ��ջ��Ԫ�أ����ڵ�ǰ���ִ���ջ��Ԫ�ص����֣�����һ���ǵ�һ������ջ��Ԫ�ص�����ֱ������±����Ƕ��ߵľ��롣
    //�������µ�ջ��Ԫ�أ�ֱ����ǰ����С�ڵ���ջ��Ԫ��ֹͣ��Ȼ��������ջ�������Ϳ���һֱ���ֵݼ�ջ����ÿ�����ֺ͵�һ�������������ľ���Ҳ�����������
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(),0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> tem = {73,74,75,71,69,72,76,73};
    solution.dailyTemperatures (tem);
    return 0;
}