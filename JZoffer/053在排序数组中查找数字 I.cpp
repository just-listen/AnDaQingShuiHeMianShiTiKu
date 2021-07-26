#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] == target;
        // return upper_bound(nums.begin(), nums.end(), target) - upper_bound(nums.begin(), nums.end(), target - 1);
        return binSerach(nums, target) - binSerach(nums, target - 1);
    }
private:
    int binSerach(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int> vec({5,7,7,8,8,10});
    cout << s.search(vec, 8) << endl;
    return 0;
}