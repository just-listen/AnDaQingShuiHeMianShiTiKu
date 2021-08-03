#include<iostream>
#include<vector>
using namespace std;

// pattern: a  b  c  a  b  c  a  c  a  b
// j:       0  1  2  3  4  5  6  7  8  9
// next:   -1 -1  -1 0  1  2  3 -1  0  1 
// void BuildNext(string& pattern, vector<int>& next){
//     int m = pattern.size();
//     next[0] = -1;
//     int i, j;
//     for(j = 1; j < m; ++j){     // O(m)
//         i = next[j - 1];       // 前一个字符的 next 
//         while(i >= 0 && pattern[i + 1] != pattern[j])// 如果不等，回退 
//             i = next[i];       //i=next[next[j-1]]
//         if(pattern[i + 1] == pattern[j])            // 到某步终于等了 
//             next[j] = i + 1;   // next[j]=next[j-1]+1   i回退的次数不会超过i增加的总次数
//         else                   // 否则前面没有相等的 
//             next[j] = -1;
//     }
// }
// int KMP(string& str, string& pattern){
//     int n = str.size(), m = pattern.size();
//     if(n < m) return -1;
//     vector<int> next(m);
//     BuildNext(pattern, next);
//     int s = 0, p = 0;
//     while(s < n && p < m){
//         if(str[s] == pattern[p]){   // 当相等时，比较下一个 
//             ++s;
//             ++p;
//         }
//         else if(p > 0){             // 当不等了，pattern 回退到 next[p-1] + 1 的位置  
//             p = next[p - 1] + 1;
//         }
//         else ++s;                   // 当 p = 0 时肯定没退的 
//     }
//     return p == m ? s - m : -1;
// }
void BuildNext(string& pattern, vector<int>& next){
    int m = pattern.size();
    next[0] = -1;
    int i, j;
    for(j = 1; j < m; ++j){
        i = next[j - 1];
        while(i >= 0 && pattern[i + 1] != pattern[j])
            i = next[i];
        if(pattern[i + 1] == pattern[j])
            next[j] = i + 1;
        else next[j] = -1;
    }
}
int KMP(string& str, string& pattern){
    int n = str.size(), m = pattern.size();
    if(m > n) return -1;
    vector<int> next(m);
    BuildNext(pattern, next);
    int s = 0, p = 0;
    while(p < m){
        if(str[s] == pattern[p]){
            ++s;
            ++p;
        }
        else if(p >= 0){
            p = next[p - 1] + 1;
        }
        else 
            ++s;
    }
    return p == m ? s - m : -1;
}

int main(){
    string str = "abcabcabcacab";
    string pattern = "abcabcacab";
    cout << KMP(str, pattern) << endl;
	return 0;
}

