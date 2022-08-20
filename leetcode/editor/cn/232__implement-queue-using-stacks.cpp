#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <stack>


using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int res = output.top();
        output.pop();
        return res;
    }

    int peek() {
        // 自己实现
//        if(output.empty()){
//            while(!input.empty()){
//                output.push(input.top());
//                input.pop();
//            }
//        }
//        return output.top();


    // peek的逻辑和pop很像，所以可以复用pop的逻辑，最后在push一次元素即可
    // 复用Pop
        int res = pop();
        output.push(res);
        return res;
}
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    MyQueue myQueue;
    return 0;
}