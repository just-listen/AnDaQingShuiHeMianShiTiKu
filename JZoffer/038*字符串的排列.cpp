#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    vector<string> permutation(string s) {
        for(char ch : s) chVec.push_back(ch);
        dfs(0);
        return res;
    }
private:
    vector<char> chVec;
    vector<string> res;
    void dfs(int idx){
        if(idx == chVec.size() - 1){
            res.emplace_back(chVec.begin(), chVec.end());
            return;
        }
        unordered_set<char> uset;
        for(int i = idx; i < chVec.size(); ++i){
            if(uset.count(chVec[i])) continue;
            uset.insert(chVec[i]);
            swap(chVec[i], chVec[idx]);
            dfs(idx + 1);
            swap(chVec[i], chVec[idx]);
        }
    }
};

int main(){
    string str;
    cin >> str;
    Solution s;
    vector<string> vec(move(s.permutation(str)));
    for(string st : vec){
        cout << st << " ";
    }
    return 0;
}