#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for(int i = 0; i < nums.size(); ++i){
            while(!deq.empty() && nums[i] > nums[deq.back()]) deq.pop_back();
            if(!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            if(i >= k - 1) res.push_back(nums[deq.front()]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec({1,3,-1,-3,5,3,6,7});
    vector<int> res = s.maxSlidingWindow(vec, 3);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}