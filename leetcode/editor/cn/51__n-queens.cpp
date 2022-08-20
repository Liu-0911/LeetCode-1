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
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string>& chessboard, int n){
        //  检查列
        for(int i = 0; i < row; i++){
            if(chessboard[i][col] == 'Q')
                return false;
        }
        //  检查45°对角线
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(chessboard[i][j] == 'Q')
                return false;
        }
        //  检查135°对角线
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtracking(vector<string>& chessboard, int row, int n){    //  row表示当前遍历到棋盘的第几行
        if(row == n){
            res.emplace_back(chessboard);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(row,col,chessboard,n)){
                chessboard[row][col] = 'Q';
                backtracking(chessboard, row + 1, n);
                chessboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chessboard(n,string(n,'.'));
        backtracking(chessboard,0,n);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}