#include<iostream>
#include<vector>
using namespace std;

const int mod = 1e9 + 7;
class Solution{
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        long res = 1;
        while(n > 4){
            res = res * 3 % mod;
            n -= 3;
        }
        return res * n % mod;

        //动态规划过程中不能取余,使用long long, 还是会报错
        // vector<long long> dp(n + 1);
        // for(int i = 2; i <= n; ++i){
        //     for(int j = 1; j < i; ++j){
        //         dp[i] = max(dp[i], max((long long)j * (i - j), (long long)j * dp[i - j]));
        //     }
        // }
        // return dp[n] % mod;
    }
};

int main(){
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}