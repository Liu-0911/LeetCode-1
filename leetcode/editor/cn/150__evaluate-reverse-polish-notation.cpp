#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 使用栈
//    int evalRPN(vector<string>& tokens) {
//        stack<int> number;
//        for(string s : tokens){
//            if (s == "+" || s == "-" || s == "*" || s == "/"){
//                int num1 = number.top();
//                number.pop();
//                int num2 = number.top();
//                number.pop();
//                switch (s[0]) {    // 判断是符号还是数字
//                    case '+': number.push(num2 + num1); break;
//                    case '-': number.push(num2 - num1); break;
//                    case '*': number.push(num2 * num1); break;
//                    case '/': number.push(num2 / num1); break;
//                }
//            } else{
//                number.push(stoi(s));
//            }
//        }
//        return number.top();
//    }

    // 使用数组模拟
    int evalRPN(vector<string>& tokens) {
//        vector<int> nums (tokens.size()/2 + 1, 0);
        int size = tokens.size()/2 + 1;
        int *nums = new int[size];
//        int nums[5000] = {0};
        int index = 0;
        for(string s : tokens){
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = nums[--index];
                int num2 = nums[--index];
                switch (s[0]) {    // 判断是符号还是数字
                    case '+': nums[index++] = (num2 + num1);break;
                    case '-': nums[index++] = (num2 - num1); break;
                    case '*': nums[index++] = (num2 * num1); break;
                    case '/': nums[index++] = (num2 / num1); break;
                }
            } else{
                nums[index] = stoi(s);
                index++;
            }
            }
        return nums[0];
        }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << solution.evalRPN(tokens);
    return 0;
}