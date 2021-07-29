#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 归并排序  $O(NlogN)$  $O(N)$  稳定
class MergeSort{
public:
    void Merge_sort(vector<int>& nums){
        int n = nums.size();
        vector<int> vec(n);
        Msort(nums, vec, 0, n - 1);
    }
private:
    void Msort(vector<int>& nums, vector<int>& vec, int left, int right){
        if(left < right){
            int mid = left + ((right - left) >> 1);
            Msort(nums, vec, left, mid);
            Msort(nums, vec, mid + 1, right);
            Merge(nums, vec, left, mid + 1, right);
        }
    }
    void Merge(vector<int>& nums, vector<int>& vec, int lBegin, int rBegin, int rEnd){
        int lEnd = rBegin - 1;
        int idx = lBegin, N = rEnd - lBegin + 1;// 此次归并从lBegin至rEnd元素个数
        while(lBegin <= lEnd && rBegin <= rEnd){
            if(nums[lBegin] <= nums[rBegin])
                vec[idx++] = nums[lBegin++];
            else 
                vec[idx++] = nums[rBegin++];
        }
        while(lBegin <= lEnd) vec[idx++] = nums[lBegin++];
        while(rBegin <= rEnd) vec[idx++] = nums[rBegin++];
        for(int i = 0; i < N; ++i){// 将vec导回nums,idx此时已经越界，所以要先减再用 
            nums[rEnd--] = vec[--idx];
        }
    }
};

int main(){
    vector<int> vec({1,3,2,4,6,8,7,5,0});
    MergeSort ms;
    ms.Merge_sort(vec);
    for(int num : vec){
        cout << num << " ";
    }
    
    return 0;
}