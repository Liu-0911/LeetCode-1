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
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // ��iΪ����
//            cout<<"����Ϊ"<<i<<" "<<i<<"���Ϊ"<<extend(s, i, i, s.size())<<endl;
            result += extend(s, i, i + 1, s.size()); // ��i��i+1Ϊ����
//            cout<<"����Ϊ"<<i<<" "<<i + 1<<"���Ϊ"<<extend(s, i, i + 1, s.size())<<endl;
//            getchar();
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
//    public:
//        int countSubstrings(string s) {
//            int n = s.size(), ans = 0;
//            for (int i = 0; i < 2 * n - 1; ++i) {
//                int l = i / 2, r = i / 2 + i % 2;
//                int tmp = 0;
//                cout<<"l="<<l<<" r="<<r;
//                while (l >= 0 && r < n && s[l] == s[r]) {
//                    --l;
//                    ++r;
//                    ++ans;
//                    ++tmp;
//                }
//                cout<<" ���Ϊ "<<tmp<<endl;
//            }
//            return ans;
//        }
    };
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    string s = "aaa";
    solution.countSubstrings (s);
    return 0;
}