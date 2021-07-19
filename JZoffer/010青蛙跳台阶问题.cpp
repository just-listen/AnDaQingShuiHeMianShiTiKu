#include<iostream>

using namespace std;

class Solution{
public:
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        int dp0 = 0, dp1 = 1, res = 0;
        for(int i = 0; i < n; ++i){
            res = (dp0 + dp1) % int(1e9 + 7);
            dp0 = dp1;
            dp1 = res;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.numWays(7) << endl;
    return 0;
}