#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //        执行耗时:148 ms,击败了32.86% 的C++用户
    //        内存消耗:71.3 MB,击败了11.59% 的C++用户
//    int totalFruit(vector<int>& fruits) {
//        int head =0, tail = 0; // 滑动区间为[tail,head]
//        int kindOfFruits = 0;
//        int numOfFruits = 0;
//        unordered_map<int,int> fruitmap;
//        for(;head < fruits.size();head++){
//            if(fruitmap[fruits[head]] == 0)
//                kindOfFruits++;
//            fruitmap[fruits[head]]++;
//            while(kindOfFruits > 2){
//                if(fruitmap[fruits[tail]] == 1)
//                    kindOfFruits--;
//                fruitmap[fruits[tail]]--;
//                tail++;
//            }
//            numOfFruits = (head - tail + 1) > numOfFruits ? (head - tail + 1) : numOfFruits;
//        }
//        return numOfFruits;
//    }


    // 优化版本 主要思路是利用数组代替hashmap
//    执行耗时:76 ms,击败了96.26% 的C++用户
//    内存消耗:64.9 MB,击败了52.01% 的C++用户

    int totalFruit(vector<int>& fruits) {
        int head =0, tail = 0; // 滑动区间为[tail,head]
        int kindOfFruits = 0;
        int numOfFruits = 0;
//        int *fruitmap = new int[fruits.size()]{0}; //定义了一个长度为fruits.size()且全部初始化为0的数组
        int fruitmap[99999] = {0};
        for(;head < fruits.size();head++){
            if(fruitmap[fruits[head]] == 0)
                kindOfFruits++;
            fruitmap[fruits[head]]++;
            while(kindOfFruits > 2){
                if(fruitmap[fruits[tail]] == 1)
                    kindOfFruits--;
                fruitmap[fruits[tail]]--;
                tail++;
            }
            numOfFruits = (head - tail + 1) > numOfFruits ? (head - tail + 1) : numOfFruits;
        }
//        delete[] fruitmap;
        return numOfFruits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<int> fruits = {1,2,1};
    cout<<solution.totalFruit(fruits)<<endl;
    return 0;
}