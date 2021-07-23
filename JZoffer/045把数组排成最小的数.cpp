#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        string res = "";
        for(int num : nums){
            res += to_string(num);
        }
        return res;
    }
    string minNumber(vector<int>& nums) {
        auto cmp = [&](string& a, string& b){return a + b < b + a;};
        vector<string> strVec;
        for(int num : nums){
            strVec.push_back(to_string(num));
        }
        sort(strVec.begin(), strVec.end(), cmp);
        string res = "";
        for(string str : strVec){
            res += str;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec({3,30,34,5,9});
    cout << s.minNumber(vec) << endl;
    return 0;
}