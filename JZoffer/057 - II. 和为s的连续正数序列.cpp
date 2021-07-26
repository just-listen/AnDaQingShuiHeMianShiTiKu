#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    // 譬如说如果有2个连续的数之和等于target，那么相差为1， (target - 1) % 2 == 0， 
    //      且数组一定是从 (target - 1) / 2开始的，数组的元素就是2个；
    // 如果是3个连续的数组，那么三个数之间相差为1、2，(target - 1 - 2) % 3 == 0，
    //      且数组一定是从 (target - 1 - 2) / 3开始的，数组元素是3个，
    // 依次类推，但是注意target必须是大于0的数，且res需要倒序。
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int m = 1;
        while(m < target / 2 + 1){
            target -= m;
            ++m;
            if(target % m == 0) {
                vector<int> vec;
                for(int i = target / m; i < target / m + m; ++i){
                    vec.push_back(i);
                }
                res.push_back(vec);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;
    
    return 0;
}