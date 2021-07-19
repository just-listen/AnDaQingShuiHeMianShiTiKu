#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        // 定义访问数组
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 横坐标，纵坐标，横、纵坐标数位和，标记数组
        return dfs(0, 0, 0, 0, visited);
    }
private:
    int m, n, k;
    int dfs(int i, int j, int si, int sj, vector<vector<bool>>& visited){
        // 下标越界，数位和大于指定值以及已经访问过都会直接返回0
        if(i >= m || j >= n || si + sj > k || visited[i][j] == true) return 0;
        visited[i][j] = true;
        //适用范围是[0,100)
        // 1.当m或者n从i9进位成(i+1)0时，数位和减小了8
        // 2.当m或者n在个位数从0到8的范围内加1时，数位和增加了1。
        // 至于为什么只向右和向下扩张是因为不用回溯已走过的路径，扩张的路径只会向下或者向右
        // 返回 1 + 右方搜索的可达解总数 + 下方搜索的可达解总数
        return 1 + dfs(i + 1, j, (i + 1) % 10 == 0 ? si - 8 : si + 1, sj, visited) +
            dfs(i, j + 1, si, (j + 1) % 10 == 0 ? sj - 8 : sj + 1, visited);
    }
    // int movingCount(int m, int n, int k) {
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
    //     queue<vector<int>> que;
    //     que.push({0, 0, 0, 0});
    //     int res = 0;
    //     while(!que.empty()){
    //         vector<int> vec(move(que.front()));
    //         que.pop();
    //         int i = vec[0], j = vec[1], si = vec[2], sj = vec[3];
    //         if(i >= m || j >= n || si + sj > k || visited[i][j]) continue;
    //         visited[i][j] = true;
    //         ++res;
    //         que.push({i + 1, j, (i + 1) % 10 == 0 ? si - 8 : si + 1, sj});
    //         que.push({i, j + 1, si, (j + 1) % 10 == 0 ? sj - 8 : sj + 1});
    //     }
    //     return res;
    // }
};

int main(){
    Solution s;
    cout << s.movingCount(11, 8, 16) << endl;
    return 0;
}