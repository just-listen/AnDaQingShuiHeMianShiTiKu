#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int findNthDigit(int n) {
        int digit = 1;
        long long int start = 1, count = 9;
        while(n > count){
            n -= count;
            start *= 10;
            digit++;
            count = 9 * start * digit;  
        }
        int num = (n - 1) / digit + start;
        string str = to_string(num);
        return str[(n - 1) % digit] - '0';
    }
};

int main(){
    Solution s;
    cout << s.findNthDigit(11) << endl;
    return 0;
}