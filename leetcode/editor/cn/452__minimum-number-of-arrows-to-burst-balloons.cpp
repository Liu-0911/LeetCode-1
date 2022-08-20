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
private:
    static bool cmp(const vector<int> a, const vector<int> b){  //  将vector按照第一个元素从小到大排序
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 2)
            return points.size();
        sort(points.begin(),points.end());
        int res = 1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > points[i - 1][1]) //  如果气球i和气球i - 1不挨着则需要多一根箭
                res += 1;
            else{
                points[i][1] = min(points[i - 1][1],points[i][1]);
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