#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0, x = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += x == num ? 1 : -1;
        }
        return x;

        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];

        // unordered_map<int, int> map;
        // int n = nums.size() / 2;
        // for(int num : nums) {
        //     if(map.count(num))
        //         map[num]++;
        //     else
        //         map[num]=1;
        //     if(map[num] > n) {
        //         return num;
        //     }
        // }
        // return 0;
    }
};

int main(){
    vector<int> vec({1, 2, 3, 2, 2, 2, 5, 4, 2});
    Solution s;
    cout << s.majorityElement(vec) << endl;
    return 0;
}