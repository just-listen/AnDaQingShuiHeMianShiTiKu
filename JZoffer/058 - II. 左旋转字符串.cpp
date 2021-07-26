#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n) {
        return (s + s).substr(n, s.size());
        // string s1;
        // for(int i = n; i < s.size(); i++)
        // s1 += s[i];
        // for(int i = 0;i<n;i++)
        // s1 += s[i];
        // return s1;

        // //求余运算简化代码
        // string s1;
        // for(int i = n;i<n+s.size();i++)
        // s1 += s[i%s.size()];
        // return s1;
    }
};

int main(){
    Solution s;
    string str = "abcdefg";
    cout << s.reverseLeftWords(str, 2) << endl;
    return 0;
}