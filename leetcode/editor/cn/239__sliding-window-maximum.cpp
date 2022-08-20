#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 设计单调队列的时候，pop，和push操作要保持如下规则：
    //pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
    //push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
    //保持如上规则，每次窗口移动的时候，只要问que.front()就可以返回当前窗口的最大值。
    class BigToSmallSingalQueue{
    public:
        deque<int> que;  // 双向队列
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        void pop(int value){
            if(!que.empty() && value == que.front())
                que.pop_front();
        }
        // 查询当前窗口最大值
        int front(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        BigToSmallSingalQueue bigToSmallSingalQueue;
        vector<int> res;
        for(int i = 0;i < k;i++)
            bigToSmallSingalQueue.push(nums[i]);
        res.emplace_back(bigToSmallSingalQueue.front());
        for(int i = k;i < nums.size();i++){
            bigToSmallSingalQueue.push(nums[i]);
            bigToSmallSingalQueue.pop(nums[i - k]);
            res.emplace_back(bigToSmallSingalQueue.front());
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}