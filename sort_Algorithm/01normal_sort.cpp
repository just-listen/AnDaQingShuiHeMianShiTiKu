#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; ++i){     //N-1次冒泡
        bool isChanged = false;         //标识是否发生了交换
        for(int j = 0; j < n - i - 1; ++j){
            if(nums[j] > nums[j + 1]){
                isChanged = true;
                swap(nums[j], nums[j + 1]);
            }
        }
        if(!isChanged) break;   //已经有序
    }
}

void Insert_sort(vector<int>& nums){
    int n = nums.size();
    for(int i = 1; i < n; ++i){// 第一个已经成序 
        int tmp = nums[i];      // 摸出下一张牌
        int j = i;              // 新牌落位时使j有效
        for(; j > 0 && tmp < nums[j - 1]; --j){
            nums[j] = nums[j - 1];// 移出空位
        }
        nums[j] = tmp;            // 新牌落位
    }
}

void Shell_sort(vector<int>& nums){
    int n = nums.size();
    for(int D = n / 2; D > 0; D /= 2){// 希尔增量序列
        for(int i = D; i < n; ++i){   // 插入排序
            int tmp = nums[i];
            int j = i;
            for(; j >= D && tmp < nums[j - D]; j -= D){
                nums[j] = nums[j - D];
            }
            nums[j] = tmp;
        }
    }
}

int main(){
    vector<int> vec({1,3,2,4,6,8,7,5,0});
    // Bubble_sort(vec);
    // Insert_sort(vec);
    Shell_sort(vec);
    for(int num : vec){
        cout << num << " ";
    }
    return 0;
}