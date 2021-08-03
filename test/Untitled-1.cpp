#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int row = static_cast<int> (log(label) / log(2) + 1);
        //恰好也是那一层的第一个节点（正常完全二叉树的第一个节点）
        int rowStart = static_cast<int> (pow(2, row - 1));
        vector<int> ret(row);
        while (row > 0)      
        {
            ret[row - 1] = label;
            label = rowStart + (rowStart - (label - rowStart + 1));
            label = label / 2;
            rowStart = rowStart / 2;
            --row;
        }
        return ret;
    }
};

int main(){
    Solution s;
    s.pathInZigZagTree(14);
    return 0;
}