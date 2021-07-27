#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int lastRemaining(int n, int m) {
        // if(n == 1) return 0;
        // int x = lastRemaining(n - 1, m);
        // return (m + x) % n;
        
        int res = 0;
        for(int i = 2; i <= n; ++i){
            res = (m + res) % i;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.lastRemaining(10, 17) << endl;
    return 0;
}