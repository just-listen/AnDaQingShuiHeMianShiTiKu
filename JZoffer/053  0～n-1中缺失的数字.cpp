#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] != mid) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int> vec({0,1,2,3,4,5,6,7,9});
    cout << s.missingNumber(vec) << endl;
    return 0;
}