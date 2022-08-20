#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return [];
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        int num = 0, target = matrix.size() * matrix[0].size();
        vector<int> mat(target,0);
        while(num < target){
            for(int i = l; i <= r; i++) mat[num++] = matrix[t][i] ; // left to right.
            t++;
            for(int i = t; i <= b; i++) mat[num++] = matrix[i][r] ; // top to bottom.
            r--;
            for(int i = r; i >= l; i--) mat[num++] = matrix[b][i] ; // right to left.
            b--;
            for(int i = b; i >= t; i--) mat[num++] = matrix[i][l] ; // bottom to top.
            l++;
        }
        return mat;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix, int a)
    {
        if (matrix.empty()) return {};
        vector<int> res;
        int l = 0;                      //左边界
        int r = matrix[0].size() - 1;   //右边界
        int t = 0;                      //上边界
        int b = matrix.size() - 1;      //下边界
        while (true)
        {
            //left -> right
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if (++t > b) break;
            //top -> bottom
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if (--r < l) break;
            //right -> left
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if (--b < t) break;
            //bottom -> top
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



int main(){
    int m = 3; // 行
    int n = 4; // 列
    int num = 1;
    Solution solution;
    vector<vector<int> > mat(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            mat[i][j] = num++;
    }
    auto resu = solution.spiralOrder(mat);
    auto resu2 = solution.spiralOrder(mat,1);
    for(auto i : resu)
        cout<<i<<" ";
    cout<<endl;
    for(auto i : resu2)
        cout<<i<<" ";
    auto c = {1,2,3};

    return 0;
}