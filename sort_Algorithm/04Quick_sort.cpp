#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 快速排序  $O(NlogN)$  $O(logN)$  不稳定
class QuickSort{
public:
    void Quick_sort(vector<int>& nums){
        int n = nums.size();
        Quick_sort(nums, 0, n - 1);
    }
private:
    void Quick_sort(vector<int>& nums, int left, int right){
        if(left >= right) return ;
        int j = partition(nums, left, right);
        Quick_sort(nums, left, j - 1);
        Quick_sort(nums, j + 1, right);
    }
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i = left, j = right + 1;
        while(i < j){
            while(++i <= right && nums[i] < pivot);
            while(left <= --j && nums[j] > pivot);
            if(i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
};

// int pivot = nums[left];
//         int i = left, j = right + 1;
//         while(i < j){
//             while(++i <= right && nums[i] < pivot);
//             while(left <= --j && nums[j] > pivot);
//             if(i >= j) break;
//             swap(nums[i], nums[j]); 
//         }
//         cout << i << ' ' << j << "   ";
//         for(int num : nums){
//             cout << num << ' ';
//         }
//         cout << endl;
//         swap(nums[left], nums[j]);
//         return j;
int main(){
    vector<int> vec({1,3,2,4,6,8,7,5,0,0,9});
    QuickSort qs;
    qs.Quick_sort(vec);
    for(int num : vec){
        cout << num << ' ';
    }
    return 0;
}