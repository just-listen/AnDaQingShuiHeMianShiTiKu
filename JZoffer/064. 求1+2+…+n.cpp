#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int res=0;
    int sumNums(int n) {
        bool x = (n > 1) && sumNums(n - 1);
        res += x;
        return res;
    }
};

int main(){
    Solution s;
    
    return 0;
}