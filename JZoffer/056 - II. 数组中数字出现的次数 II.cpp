#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int singleNumber(vector<int>& nums) {
        vector<int> vec(32);
        for(int num : nums){
            for(int i = 0; i < 32; ++i){
                vec[i] += num & 1;
                num >>= 1;
            }
        }
        int res = 0, m = 3;
        for(int i = 31; i >= 0; --i){
            res <<= 1;
            res |= vec[i] % 3;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec({9,1,7,9,7,9,7});
    cout << s.singleNumber(vec) << endl;
    return 0;
}