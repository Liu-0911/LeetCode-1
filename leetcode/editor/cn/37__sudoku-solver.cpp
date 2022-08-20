#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<bitset>
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
//class Solution {
//private:
//    bool isValid(vector<vector<char>>& board, int row, int col, int val){ //  (i,j)���λ�÷�k�Ƿ�Ϸ�
//        for(int i = 0; i < 9; i++){ //  �����
//            if(board[row][i] == val)
//                return false;
//        }
//        for(int i = 0; i < 9; i++){ //  �����
//            if(board[i][col] == val)
//                return false;
//        }
//        int smallrow = (row / 3) * 3;   //  ��������һ��9������
//        int smallcol = (col / 3) * 3;
//        for(int i = smallrow; i < smallrow + 3; i++){   //  �ж�9����
//            for(int j = smallcol; j < smallcol + 3; j++){
//                if(board[i][j] == val)
//                    return false;
//            }
//        }
//        return true;
//    }
//    bool backtracking(vector<vector<char>>& board){
//        for(int i = 0; i < board.size(); i++){  //  ������
//            for(int j = 0; j < board[0].size(); j++){   //  ������
//                if(board[i][j] != '.')  //  �����ǰλ�ò��ǿ�������
//                    continue;
//                for(char k = '1'; k <= '9'; k++){    //
//                    if(isValid(board,i,j,k)){
//                        board[i][j] = k;
//                        if(backtracking(board))
//                            return true;
//                        board[i][j] = '.';
//                    }
//                }
//                return false;   //  ��ǰλ��1-9���������򷵻�false
//            }
//        }
//        return true;    //  ����������û�з���false�򷵻�true
//    }
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        backtracking(board);
//        return;
//    }
//};

class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    vector<int> getNext(vector<vector<char>>& board)    //  �ҵ������������ٵĸ��ӵ�����(i,j)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }

    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.'){
                    cnt += 1;
                    continue;
                }
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;

    return 0;
}