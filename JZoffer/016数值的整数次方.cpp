#include<iostream>
#include<iomanip>
using namespace std;

class Solution{
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        long ln = n;
        double res = 1.00000;
        bool isNega = false;
        if(ln < 0){
            isNega = true;
            ln = -ln;
        }
        while(ln > 0){
            if(ln & 1) res *= x;
            x *= x;
            ln >>= 1;
        }
        return isNega ? 1 / res : res;
    }
};

int main(){
    Solution s;
    // cout.setprecision(10);
    cout << s.myPow(2.00000, 10) << endl;
    printf("%.5f\n", s.myPow(2.00000, 10));
    return 0;
}