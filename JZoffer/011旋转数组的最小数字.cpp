#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(numbers[mid] > numbers[right]) left = mid + 1;
            else if(numbers[mid] < numbers[right]) right = mid;
            else right = right - 1; 
        }
        return numbers[left];
    }
};

int main(){
    // vector<int> vec{3,4,5,1,2};
    vector<int> vec{2,2,2,0,1};
    Solution s;
    cout << s.minArray(vec) << endl;
    return 0;
}