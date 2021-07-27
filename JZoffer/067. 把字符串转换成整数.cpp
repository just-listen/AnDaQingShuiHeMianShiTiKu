#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution{
public:
    int strToInt(string str) {
        bool isNega = false;
        int i = 0, res = 0, n = str.size();
        while(i < n && str[i] == ' ') ++i;
        if(str[i] == '-') isNega = true;
        if(str[i] == '-' || str[i] == '+') ++i;
        while(i < n){
            if(!isdigit(str[i])) break;
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7))
                return isNega ? INT_MIN : INT_MAX;
            res = res * 10 + str[i] - '0';
            ++i;
        }
        return isNega ? -res : res;
    }
};

int main(){
    Solution s;
    string str = "   -42";
    cout << s.strToInt(str) << endl;
    return 0;
}