#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        vector<int> vec(n);
        return reversePairs(nums, vec, 0, n - 1);
    }
private:
    int reversePairs(vector<int>& nums, vector<int>& vec, int left, int right){
        if(left >= right) return 0;                 // 递归终止条件是只剩一个元素,即不存在数对
        int mid = left + ((right - left) >> 1);
        int leftNum = reversePairs(nums, vec, left, mid);       // 计算左半部分的逆序对
        int rightNum = reversePairs(nums, vec, mid + 1, right); // 计算右半部分的逆序对
        // 剪枝，即如果左右都已排好序，而且左边的最大值 <= 右边的最小值，
        // 那么就不存在跨越左边和右边的逆序对了
        if(nums[mid] <= nums[mid + 1]) return leftNum + rightNum;
        else {
            // 计算跨越左边和右边的逆序对
            int crossNum = merge(nums, vec, left, mid, right);
            return leftNum + rightNum + crossNum;
        }
    }
    int merge(vector<int>& nums, vector<int>& vec, int left, int mid, int right){
        // 本函数的前提条件是：左半部分和右半部分都是已经按升序排好序了的
        // 因为本函数是从左右部分都是只有一个元素的情况开始运行的（自底向上），所以是可以保证前提条件的
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) vec[i] = nums[i];// 先填充 vec 辅助数组
        int i = left, j = mid + 1;              // i 和 j 分别是左半部分和右半部分的起点
        for(int k = left; k <= right; ++k){
            // 假如 i 已经越过左边的边界，直接填充右半部分进 nums
            if(i == mid + 1) nums[k] = vec[j++];
            // 假如 j 已经越过右边的边界，直接填充左半部分进 nums
            else if(j == right + 1) nums[k] = vec[i++];
            // 假如左边小于等于右边，那就不是逆序对，不用修改 count
            else if(vec[i] <= vec[j]) nums[k] == vec[i++];
            else{
                // 假如左边大于右边，是逆序对，count += 当前左边 [i, mid] 的所有元素
                nums[k] = vec[j++];
                count += mid - i + 1;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    
    return 0;
}