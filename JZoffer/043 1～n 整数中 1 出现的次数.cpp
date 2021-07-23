#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int countDigitOne(int n) {
        int cur = n % 10, high = n / 10, low = 0;
        int digit = 1, res = 0;
        while(cur != 0 || high != 0){
            if(cur == 0) res += high * digit;
            else if(cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.countDigitOne(12) << endl;
    return 0;
}