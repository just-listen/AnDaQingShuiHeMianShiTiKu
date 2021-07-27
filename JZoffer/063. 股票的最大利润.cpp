#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minP = INT_MAX;
        for(int i = 0; i < prices.size(); ++i){
            minP = min(minP, prices[i]);
            res = max(res, prices[i] - minP);
        }
        return res;
    }
    int maxProfit_122(vector<int>& prices){
        int res = 0, n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // dp[i][0]为未持有股票最大利润,dp[i][1]为持有最大利润
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
    int maxProfit_123(vector<int>& prices){
        int res = 0, n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5));
        // dp[i][0]为一直未持有,dp[i][1]为第一次持有,dp[i][2]为第一次卖出
        // dp[i][3]为第二次持有,dp[i][4]为第二次卖出
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0;
        dp[0][3] = -prices[0], dp[0][4] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[n - 1][4];
    }
};

int main(){
    Solution s;
    
    return 0;
}