#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<limits.h>
using namespace std;

struct Task{
    int taskId;
    int depID;
};

class Solution0{
public:
    vector<int> task_execute(vector<Task> tasks){
        int n = tasks.size();
        unordered_map<int, vector<int>> umap;
        for(auto task : tasks){
            umap[task.taskId].push_back(task.depID);
        }
    }
};

class Solution{
public:
    //在 ss 上滑动窗口，通过移动 rr 指针不断扩张窗口。
    //当窗口包含 tt 全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
    string minWindow(string s, string t) {
        for(auto& ch : t){
            tmap[ch]++;
        }
        int left = 0, right = -1;
        int idxL = -1, len = INT_MAX, n = s.size();
        while(right < n){
            if(tmap.count(s[++right])) smap[s[right]]++;
            while(isSame() && left <= right){
                if(right - left + 1 < len){
                    len = right - left + 1;
                    idxL = left;
                }
                if(tmap.count(s[left])) --smap[s[left]];
                ++left;
            }
        }
        return idxL == -1 ? "" : s.substr(idxL, len);
    }
private:
    unordered_map<char, int> smap, tmap;
    bool isSame(){
        for(auto& it : tmap){
            if(it.second > smap[it.first]) return false;
        }
        return true;
    }
};

int main(){
    // Solution s;

    // int *test = new int(4);
    // free(test);
    // free(nullptr);
    string s = "ADOBECODEBANC", t = "ABC";
    Solution ss;
    cout << ss.minWindow(s, t);
    return 0;
}

