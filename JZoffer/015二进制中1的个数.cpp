#include<iostream>

using namespace std;

class Solution{
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n &= n -1;
            ++res;
        }
        return res;

        // return __builtin_popcount(n);
    }
};

int main(){
    Solution s;
    // uint32_t n = 4294967293;
    uint32_t n = 128;
    cout << s.hammingWeight(n) << endl;
    return 0;
}