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
    // unordered_map<��������, map<�������, �������>> targets
    unordered_map<string, map<string, int>> targets;    //   �ڲ�ʹ�õ�map������ģ����Զ���ͬһ����������Ŀ�ĵؽ����ֵ�������
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
            targets[n[0]][n[1]]++;  //  ��¼ӳ���ϵ
//            for(auto [key,value] : targets){
//                cout<<"����������"<<key<<"  ";
//                for(auto [innerkey,innervalue] : value){
//                    cout<<"���������"<<innerkey<<" "<<"���������"<<innervalue<<endl<<"����������"<<key<<"  ";
//                }
//                cout<<endl;
//            }
//            cout<<"----------------------------------------------------"<<endl;
        }

//        for(auto & target : targets){
//            cout<<"����������"<<target.first<<"  ";
//            auto inerIter = target.second.begin();
//            cout<<"���������"<<inerIter->first<<" "<<"���������"<<inerIter->second<<endl;
//        }
//        for(auto & target : targets){
//            cout<<target.first<<"  ";
//            auto inerIter = target.second.begin();
//            cout<<inerIter->first<<" "<<inerIter->second<<endl;
//        }
//        for(auto [key,value] : targets){
//            cout<<"����������"<<key<<"  ";
//            for(auto [innerkey,innervalue] : value){
//                cout<<"���������"<<innerkey<<" "<<"���������"<<innervalue;
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