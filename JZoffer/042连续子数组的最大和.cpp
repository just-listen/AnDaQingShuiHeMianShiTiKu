#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), x = nums[0], res = nums[0];
        for(int i = 1; i < n; ++i){
            x = max(x, 0) + nums[i];
            res = max(x, res);
        }
        return res;
    }
};

int main(){
    Solution s;
    
    return 0;
}