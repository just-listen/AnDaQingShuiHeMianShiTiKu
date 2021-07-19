#include<iostream>
#include<vector>
using namespace std;

//从右上角开始遍历
class Solution{
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if(m == 0) return false;
        int n = array[0].size();
        int row = 0, col = n - 1;
        while(row < m && col >= 0){
            if(target < array[row][col]) col--;
            else if(target > array[row][col]) row++;
            else return true;
        }
        return false;
    }
};

int main(){
    int target = 7;
    vector<vector<int>> vec({{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}});
    Solution s;
    cout << "answer: " << s.Find(target, vec) << endl;
    return 0;
}