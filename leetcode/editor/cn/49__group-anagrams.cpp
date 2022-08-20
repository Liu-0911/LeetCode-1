#include<vector>
#include<iostream>#
#include <map>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res ;
        map<string, vector<string>> map ;

        // 统计string的各字母频次,以频次为key直接加入队列
        for (auto s : strs) {
            string sts = string(26, '0') ;
            for (auto c : s)  ++ sts[c-'a'] ;
            map[sts].emplace_back (s) ;
        }
        for (auto e : map)  res.emplace_back(e.second) ;

        return res ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> cache;
        vector<vector<string>> res;
        for (auto& s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (cache.find(tmp) == cache.end()) {  // 在hashmap中没找到字符串tmp
                cache[tmp] = res.size();    // 新的字符串tmp的组号
                res.emplace_back(vector<string>{s});
            } else {
                res[cache[tmp]].emplace_back(s);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    return 0;
}