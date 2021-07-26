#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    char firstUniqChar(string& s) const {
        int n = s.size();
        if(n == 0) return ' ';
        vector<int> chVec(26);
        for(char ch : s){
            chVec[ch - 'a']++;
        }
        for(char ch : s){
            if(chVec[ch - 'a'] == 1) return ch;
        }
        return ' ';
    }
};

int main(){
    Solution s;
    string str("abaccdeff");
    cout << s.firstUniqChar(str) << endl;
    return 0;
}