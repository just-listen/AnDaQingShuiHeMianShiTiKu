#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
public:
    // int lengthOfLongestSubstring(string s) {
    //     int res = 0, tmp = 0;
    //     unordered_map<char, int> umap;
    //     for(int i = 0; i < s.size(); ++i){
    //         int idx = -1;
    //         if(umap.count(s[i])) idx = umap[s[i]];
    //         umap[s[i]] = i;
    //         tmp = (i - idx) > tmp ? tmp + 1 : i - idx;
    //         res = max(res, tmp);
    //     }
    //     return res;
    // }
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1;
        unordered_map<char, int> umap;
        for(int i = 0; i < s.size(); ++i){
            if(umap.count(s[i])) left = max(left, umap[s[i]]);
            umap[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}