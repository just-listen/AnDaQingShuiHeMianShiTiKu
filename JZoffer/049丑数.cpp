#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int nthUglyNumber(int n) {
        if(n <= 6) return n;
        vector<int> dp(n);
        dp[0] = 1;
        int cnt2 = 0, cnt3 = 0, cnt5 = 0;
        for(int i = 1; i < n; ++i){
            int a = 2 * dp[cnt2], b = 3 * dp[cnt3], c = 5 * dp[cnt5];
            dp[i] = min(a, min(b, c));
            if(dp[i] == a) ++cnt2;
            if(dp[i] == b) ++cnt3;
            if(dp[i] == c) ++cnt5; 
        }
        return dp[n - 1];
    }
};

int main(){
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    return 0;
}