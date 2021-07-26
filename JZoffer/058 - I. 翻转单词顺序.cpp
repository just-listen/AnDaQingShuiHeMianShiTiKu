#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

class Solution{
public:
    string reverseWords(string s) {
        string str = "";
        if(s.empty()) return str;
        int i = 0, j = s.size() - 1;
        for(; j >= 0; --j){
            if(s[j] != ' '){
                i = j;
                while(i >= 0 && s[i] != ' ') --i;
                str += s.substr(i + 1, j - i) + " ";
                j = i;
            }
        }
        if(str.size() > 0) str.pop_back();
        return str;
    }
};
class Solution2{
public:
    string reverseWords(string s) {
        string str = "";
        if(s.empty()) return str;
        stack<string> stk;
        istringstream iss(s);
        string tmp;
        while(iss >> tmp) stk.push(tmp);
        while(!stk.empty()){
            str += stk.top() + " ";
            stk.pop();
        }
        if(str.size() > 0) str.pop_back();
        return str;
    }
};
int main(){
    Solution2 s;
    string str = "  hello world!  ";
    cout << s.reverseWords(str) << endl;
    return 0;
}