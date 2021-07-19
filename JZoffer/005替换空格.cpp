#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    string replaceSpace(string& s) {
        if(s.empty()) return s;
        string res = "";
        for(char ch : s){
            if(ch == ' ') res.append("%20");
            else res.push_back(ch);
        }
        return res;

        //C++中string特性，可以不重新拷贝而像数组一样重新分配大小
        // int count = 0;
        // int len = s.length();
        //  // 统计空格数量
        // for(char c : s)
        //     if(c == ' ') 
        //         count++;
        // // 修改 s 长度
        // s.resize(len + 2*count);
        //  // 倒序遍历修改
        // for(int i = len-1,j = s.length()-1;i<j;i--,j--){
        //     if(s[i] != ' ')
        //         s[j]=s[i];
        //     else{
        //         s[j--] = '0';
        //         s[j--] = '2';
        //         s[j] = '%';
        //     }
        // }
        // return s;

        // return s.replace(" ","%20");
    }
};

int main(){
    string s = "We are happy.";
    Solution so;
    cout << so.replaceSpace(s) << endl;
    return 0;
}