#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0) return "";
        string ss(s);
        reverse(ss.begin(), ss.end());
        string str = s + "#" + ss;
        vector<int> next(str.size());
        int ret = getNext(str, next);
        return ss + s.substr(ret + 1, s.size() - ret);
    }
private:
    int getNext(string& pattern, vector<int>& next){
        int m = pattern.size();
        next[0] = -1;
        int i, j;
        for(j = 1; j < m; ++j){
            i = next[j - 1];
            while(i >= 0 && pattern[i + 1] != pattern[j])
                i = next[i];
            if(pattern[i + 1] == pattern[j])
                next[j] = i + 1;
            else 
                next[j] = -1;
        }
        return next[j - 1];
    }
};

int main(){
    string str = "aacecaaa";
    Solution s;
    cout << s.shortestPalindrome(str) << endl;
	return 0;
}