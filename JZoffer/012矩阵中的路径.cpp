#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), len = word.size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int m, n, len;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[k]) return false;
        if(k == len - 1) return true; 
        //做标记是为了防止标记字符与矩阵原有字符重复。
        //当存在重复时，此算法会将矩阵原有字符认作标记字符，从而出现错误。
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1)
            ||dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);       
        board[i][j] = word[k];
        return res;
    }
};

int main(){
    vector<vector<char>> vec = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string str = "ABCCED";
    Solution s;
    cout << s.exist(vec, str) << endl;
    return 0;
}