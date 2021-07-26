#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int dp0 = 1, dp1 = 1;
        for(int i = 1; i < str.size(); ++i){
            string tmp = str.substr(i - 1, 2);
            dp0 = (tmp >= "10" && tmp <= "25") ? dp0 + dp1 : dp1;
            swap(dp0, dp1);
        }
        return dp1;
    }
};

class Solution2{
public:
    int translateNum(int num) {
        int low = num % 10;
        int dp0 = 1, dp1 = 1;
        while(num){
            num /= 10;
            int tmp = num % 10 * 10 + low;
            dp1 = (tmp >= 10 && tmp <= 25) ? dp0 + dp1 : dp0;
            swap(dp0, dp1);
            low = num % 10; 
        }
        return dp0;
    }
};

int main(){
    Solution2 s;
    cout << s.translateNum(12258) << endl;
    return 0;
}