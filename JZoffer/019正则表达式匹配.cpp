#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    bool isMatch(string& s, string& p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        //初始化首行
        for(int j = 2; j <= n; j += 2){
            if(dp[0][j - 2] && p[j - 1] == '*') dp[0][j] = true;
        }
        //状态转移
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j - 1] == '*'){
                    if(dp[i][j - 2]) dp[i][j] = true;// aaa aa*a
                    else if(dp[i][j - 1]) dp[i][j] = true;
                    else if(dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true;
                    else if(dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;
                }
                else{
                    if(dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;
                    else if(dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};

class Solution2{
public:
    bool isMatch(string s, string p){
        if(p.empty()) return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if(p.size() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2)) || 
            (first_match && isMatch(s.substr(1), p));
        else 
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};

int main(){
    string str = "aab";
    string pattern = "c*a*b";
    Solution s;
    cout << s.isMatch(str, pattern) << endl;
    return 0;
}