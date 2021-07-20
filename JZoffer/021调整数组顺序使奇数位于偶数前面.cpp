#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < right && nums[left] % 2 == 1) ++left;
            while(left < right && nums[right] % 2 == 0) --right;
            if(left < right) swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

int main(){
    vector<int> vec{1,2,3,4};
    Solution s;
    s.exchange(vec);
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << " ";
    }
    return 0;
}