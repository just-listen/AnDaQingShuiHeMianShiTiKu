#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(int num : nums){
            ret ^= num;
        }
        int div = 1;
        while((div & ret) == 0) div <<= 1;
        int a = 0, b = 0;
        for(int num : nums){
            if(num & div) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};

int main(){
    Solution s;
    vector<int> vec({1,2,10,4,1,4,3,3});
    vector<int> res = s.singleNumbers(vec);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}