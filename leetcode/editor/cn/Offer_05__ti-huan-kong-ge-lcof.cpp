#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 从前向后填充就是O(n^2)的算法了，因为每次添加元素都要将添加元素之后的所有元素向后移动。
    // 其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。
    string replaceSpace(string &s) {
        int numOfSpcae = 0;
        int sizeOfOldS = s.size();
        for(auto c : s)
            if(c == ' ')
                numOfSpcae++;
        s.resize(sizeOfOldS + numOfSpcae * 2);// 扩充string的大小
        for(int left = sizeOfOldS - 1, right = s.size() - 1;left < right;left--, right-- ){ // 使用双指针，left指向原string末尾，right指向新string末尾
            if(s[left] != ' ')
                s[right] = s[left];
            else{
                s[right] = '0';
                s[right - 1] = '2';
                s[right - 2] = '%';
                right -= 2;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    return 0;
}