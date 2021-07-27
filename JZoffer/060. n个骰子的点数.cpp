#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    // n个骰子的概率数组tmp长度为5*n+1，
    // 其为n-1个骰子的概率数组与pre(6,1.0/6)相乘得到,tmp[j+k] += pre[j]*1.0/6
    vector<double> dicesProbability(int n) {
        vector<double> pre(6, 1.0/6);
        for(int i = 2; i <= n; ++i){
            vector<double> vec(5 * i + 1);
            for(int j = 0; j < pre.size(); ++j){
                for(int k = 0; k < 6; ++k){
                    vec[j + k] += pre[j] * 1.0 / 6;
                }
            }
            pre = vec;
        }
        return pre;
    }
};

int main(){
    Solution s;
    vector<double> res = s.dicesProbability(2);
    for(double num : res){
        cout << num << " ";
    }
    return 0;
}