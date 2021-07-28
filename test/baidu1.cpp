#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Task{
    int taskId;
    int depID;
};

class Solution{
public:
    vector<int> task_execute(vector<Task> tasks){
        int n = tasks.size();
        unordered_map<int, vector<int>> umap;
        for(auto task : tasks){
            umap[task.taskId].push_back(task.depID);
        }
    }
};

int main(){
    Solution s;
    
    return 0;
}

