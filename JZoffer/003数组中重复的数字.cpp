#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//数组元素为0至n-1,把元素搬至对应位置
class Solution{
public:
    int findRepeatNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != i){
                if(nums[nums[i]] == nums[i]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};

int main(){
    vector<int> vec{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout << s.findRepeatNumber(vec) << endl;
    return 0;
}