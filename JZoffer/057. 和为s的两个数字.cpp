#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            if(nums[left] + nums[right] < target) ++left;
            else if(nums[left] + nums[right] > target) --right;
            else return {nums[left], nums[right]};
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<int> vec({10,26,30,31,47,60});
    vector<int> res = s.twoSum(vec, 40);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}