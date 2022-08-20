#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // 快慢指针 将题目抽象为循环
        // 每计算一次相当于向前移动一步，如果不是快乐数则会出现循环，类似于快慢指针寻找链表里的环
        int slow = bitSquareSum(n);
        int fast = bitSquareSum(bitSquareSum(n));
        while(slow != fast){
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }
        return fast == 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    cout<<solution.bitSquareSum(12);

    Solution sloution;
    return 0;
}