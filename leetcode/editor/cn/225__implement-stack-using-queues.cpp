#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
public:
//     一个队列实现版本
    queue<int> input;
    MyStack() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        // 在弹出元素时，将除去队列最后一个元素以外的所有元素重新插入队列即可实现模拟栈的弹出
        int size = input.size();
        size--;
        while(size--){
            input.push(input.front());
            input.pop();
        }
        int res = input.front();
        input.pop();
        return res;
    }

    int top() {
        return input.back();
    }

    bool empty() {
        return input.empty();
    }


};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    MyStack myStack;
    return 0;
}