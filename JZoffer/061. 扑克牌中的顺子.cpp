#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for(int i = 0; i < 5; ++i){
            if(nums[i] == 0) ++joker;
            else if(i > 0 && nums[i] == nums[i - 1]) return false;
        }
        return nums[4] - nums[joker] < 5;
    }
};

int main(){
    Solution s;
    vector<int> vec({0,0,1,2,5});
    cout << s.isStraight(vec) << endl;
    return 0;
}