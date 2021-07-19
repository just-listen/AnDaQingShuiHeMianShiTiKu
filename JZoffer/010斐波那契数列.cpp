#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
    int fib(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;
        // return (fib(n - 1) + fib(n - 2)) % int(1e9 + 7);
        int dp0 = 0, dp1 = 1;
        for(int i = 2; i <= n; ++i){
            dp0 = (dp0 + dp1) % int(1e9 + 7);
            swap(dp0, dp1);
        }
        return dp1;
    }
};

int main(){
    Solution s;
    cout << s.fib(5) << endl;
    return 0;
}