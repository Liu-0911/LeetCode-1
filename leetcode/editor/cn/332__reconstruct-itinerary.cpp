#include<vector>
#include<iostream>
#include<unordered_map>
#include <map>
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
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;    //   内部使用的map是有序的，会自动对同一出发机场的目的地进行字典序排序
//    vector<string> res;
    bool backtracking(vector<string> &res,int ticketNum) {
        if(res.size() == ticketNum + 1)
            return true;
        for(auto &target : targets[res[res.size() - 1]]){
            if(target.second > 0){
                res.emplace_back(target.first);
                target.second--;
                if(backtracking(res,ticketNum))
                    return true;
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for (auto &n: tickets){
            targets[n[0]][n[1]]++;  //  记录映射关系
//            for(auto [key,value] : targets){
//                cout<<"出发机场："<<key<<"  ";
//                for(auto [innerkey,innervalue] : value){
//                    cout<<"到达机场："<<innerkey<<" "<<"航班次数："<<innervalue<<endl<<"出发机场："<<key<<"  ";
//                }
//                cout<<endl;
//            }
//            cout<<"----------------------------------------------------"<<endl;
        }

//        for(auto & target : targets){
//            cout<<"出发机场："<<target.first<<"  ";
//            auto inerIter = target.second.begin();
//            cout<<"到达机场："<<inerIter->first<<" "<<"航班次数："<<inerIter->second<<endl;
//        }
//        for(auto & target : targets){
//            cout<<target.first<<"  ";
//            auto inerIter = target.second.begin();
//            cout<<inerIter->first<<" "<<inerIter->second<<endl;
//        }
//        for(auto [key,value] : targets){
//            cout<<"出发机场："<<key<<"  ";
//            for(auto [innerkey,innervalue] : value){
//                cout<<"到达机场："<<innerkey<<" "<<"航班次数："<<innervalue;
//            }
//            cout<<endl;
//        }
        system("pause");
        res.emplace_back("JFK");
        backtracking(res,tickets.size());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution solution;
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    solution.findItinerary(tickets);
    return 0;
}