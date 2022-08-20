#include<vector>
#include<iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    执行耗时:0 ms,击败了100.00% 的C++用户
//    内存消耗:6.4 MB,击败了71.54% 的C++用户
    vector<vector<int>> generateMatrix(int n) {
//        vector<vector<int>> mat(row, vector<int>(column, a)); //初始化row*column二维动态数组，初始化值为a
        int l = 0, r = n - 1, t = 0, b = n - 1;// 设定上下左右四个边界
        vector<vector<int> > mat(n, vector<int>(n,0));
        int num = 1, target = n * n;
        while(num <= target){
            for(int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
            t++;
            for(int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
            r--;
            for(int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
            b--;
            for(int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
            l++;
        }
        return mat;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    int n = 3;
//    vector<vector<int> > mat(n, vector<int>(n,0));
    auto mat = solution.generateMatrix(n);
    for(auto i: mat){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}
