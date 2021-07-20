#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return {};
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        while(left <= right && top <= bottom){
            for(int col = left; col <= right; ++col) 
                res.push_back(matrix[top][col]);
            for(int row = top + 1; row <= bottom; ++row)
                res.push_back(matrix[row][right]);
            if(right - 1 >= left && bottom - 1 >= top){
                for(int col = right - 1; col > left; --col)
                    res.push_back(matrix[bottom][col]);
                for(int row = bottom; row > top; --row)
                    res.push_back(matrix[row][left]);
            }
            ++top;
            --right;
            --bottom;
            ++left;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> vec({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    Solution s;
    vector<int> res = s.spiralOrder(vec);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}