#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution{
public:
    int cuttingRope(int n) {
        //贪心
        // if(n < 2) return 0;
        // if(n == 2) return 1;
        // if(n == 3) return 2;
        // int pow3 = n / 3;
        // if(n % 3 == 1) pow3--;
        // int pow2 = (n - pow3 * 3) / 2;
        // return pow(3, pow3) * pow(2, pow2);

        //dp
        //$dp[i]= \max_{1≤j<i} {(j×(i−j),j×dp[i−j])})$
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 0;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}