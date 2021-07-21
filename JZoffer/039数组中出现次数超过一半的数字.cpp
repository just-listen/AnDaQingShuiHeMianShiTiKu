#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0, x = 0;
        for(int num : nums){
            if(votes == 0) {
                x = num;
                votes = 1;
            }
            else if(x != num) votes -= 1;
            else votes++;
        }
        return x;
    }
};

int main(){
    vector<int> vec({1, 2, 3, 2, 2, 2, 5, 4, 2});
    Solution s;
    cout << s.majorityElement(vec) << endl;
    return 0;
}