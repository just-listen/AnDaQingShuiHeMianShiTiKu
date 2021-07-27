#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n < 1) return {};
        vector<int> res(n, 1);
        for(int i = 1; i < n; ++i){
            res[i] = res[i - 1] * a[i - 1];
        }
        int pre = 1;
        for(int i = n - 2; i >= 0; --i){
            pre *= a[i + 1];
            res[i] *= pre;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec({1,2,3,4,5});
    vector<int> res = s.constructArr(vec);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}