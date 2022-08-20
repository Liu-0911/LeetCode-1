#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include "bitset"

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
private:
    bitset<6001> b;
    int res = -1;
public:
    int lastStoneWeightII(vector<int>& stones) {
        b[3000] = 1;
        for(const auto & stone : stones){
            b = (b << stone) | (b >> stone);
        }
        for(int i = 0; i < 3000; i++){
            if(b[3000 + i])
                return (res = i);
        }
        return -1;
    }
    void print(){
        cout<<b<<endl<<res<<endl;
        cout<<b[res + 3000]<<endl;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int changa(int &a,int &b){
    return (b = a);
}

int main(){
    Solution solution;
    vector<int> stones = {2,7,4,1,8,1};
    cout<<solution.lastStoneWeightII(stones)<<endl;
    solution.print();
    return 0;
}