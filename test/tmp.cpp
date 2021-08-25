#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
using namespace std;

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算最小航行费用
     * @param input int整型vector<vector<>> 二维网格
     * @return int整型
     */
    vector<vector<int>> myRoad;
    int res = INT_MAX;
    int n,m; 
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    struct Node
    {
    int x,y;
    } p;
 
stack<Node> tmpePath,temp;
void dfs(int x,int y,vector<vector<int> >& input,vector<vector<int> >& visit)
{
 if(x==n-1 && y==m-1)
 {
    
    vector<int> tmpRoad;

  while(!tmpePath.empty())
  {
   Node p1 = tmpePath.top();
   tmpePath.pop();
   temp.push(p1);
  }
  while(!temp.empty())
  {
   Node p1 = temp.top();
   temp.pop();
   tmpePath.push(p1);
   tmpRoad.push_back(input[p1.x][p1.y]);
  }
    // myRoad.push_back(tmpRoad);
         int F=0;
         for(int i=1; i<tmpRoad.size(); ++i){
          if(tmpRoad[i]==0){
            F += 2;
          }else{
            F += 1;
          }
      }
        res = min(res,F);
  return;
 }
 
 if(x<0 || x>=n || y<0 || y>=m)
  return;

 for(int i=0;i<4;i++)
 {
  int nx = x + dir[i][0];
  int ny = y + dir[i][1];
  if(0<=nx && nx<n && 0<=ny && ny<m && input[nx][ny]!=2 && visit[nx][ny]==0)
  {
   
   visit[nx][ny]=1;
   p.x = nx;
   p.y = ny;
   tmpePath.push(p); 
   dfs(nx,ny,input,visit); 
   visit[nx][ny]=0;
   tmpePath.pop();
  }
 }
}
  
int minSailCost(vector<vector<int> >& input) {
    n =  input.size();
    m =  input[0].size();
    vector<vector<int>> visit(n,vector<int>(m,0));
    p.x = 0;
    p.y = 0;
    tmpePath.push(p);
    dfs(0,0,input,visit);
 
//cout<<myRoad.size()<<endl;
    return res==INT_MAX?-1:res;
    
}
};

class Solution{
public:
    int minSailCost(vector<vector<int> >& input) {
        this->m = input.size(), this->n = input[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(input[i][j] == 0) input[i][j] = 2;
                else if(input[i][j] == 2) input[i][j] = -1;
            }
        }
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        dfs(input, visit, 0, 0);
        return res == INT_MAX ? -1 : res - input[0][0]; 
    }
private:
    int m, n;
    int res = INT_MAX, tmp = 0;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& vec, vector<vector<bool>>& visit, int idx1, int idx2){
        if(idx1 == m - 1 && idx2 == n - 1) {
            res = min(res, tmp + vec[idx1][idx2]);
            return;
        }
        if(idx1 < 0 || idx1 >= m || idx2 < 0 || idx2 >= n || vec[idx1][idx2] == -1 || visit[idx1][idx2]) return;
        for(int i = 0; i < 4; ++i){
            int newi = idx1 + dir[i][0];
            int newj = idx2 + dir[i][1];
            tmp += vec[idx1][idx2];
            visit[idx1][idx2] = true;
            dfs(vec, visit, newi, newj);
            visit[idx1][idx2] = false;
            tmp -= vec[idx1][idx2];
        }
    }
};


int main(){
    Solution s;
    vector<vector<int>> vec{{1,1,1,1,0},{0,1,0,1,0},{1,1,2,1,1},{0,2,0,0,1}};
    cout << s.minSailCost(vec);
    return 0;
}