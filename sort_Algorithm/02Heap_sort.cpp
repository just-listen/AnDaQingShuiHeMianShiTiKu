/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-04 14:48:56 
 * @Last Modified by:   LISTEN 
 * @Last Modified time: 2021-08-04 14:48:56 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 堆排序  $O(NlogN)$   $O(1)$  不稳定
class HeapSort{
public:
    void Heap_sort(vector<int>& nums){
        int n = nums.size();
        for(int i = n / 2; i >= 0; --i){// 先调整为最大堆
            PrecDown(nums, i, n);
        }
        for(int i = n - 1; i > 0; --i){// 将最大堆转化为最小堆
            //每次把最大堆的堆顶放到最后，再把前i个元素调整为最大堆
            swap(nums[0], nums[i]);
            PrecDown(nums, 0, i);//再调整为最大堆
        }
    }
private:
    // 将N个元素的数组中以nums[rootIdx]为根的子堆调整为最大堆
    void PrecDown(vector<int>& nums, int rootIdx, int N){
        int root = rootIdx, child;
        int tmp = nums[rootIdx];            // 取出根结点存放的值
        for(; root * 2 + 1 < N; root = child){
            child = root * 2 + 1;
            if(child != N - 1 && nums[child] < nums[child + 1]){
                ++child;                    // Child指向左右子结点的较大者
            }
            if(nums[child] <= tmp)          // 符合最大堆定义，跳出
                break;
            else
                nums[root] = nums[child];   // 下滤tmp
        }
        nums[root] = tmp;
    }
};

class STLHeap{
    priority_queue<int, vector<int>, less<int>> MaxHeap;
public:
    void STL_Heap_sort(vector<int>& nums){
        for(int num : nums){
            MaxHeap.push(num);
        }
        for(int i = 0; i < nums.size(); ++i){
            nums[nums.size() - 1 - i] = MaxHeap.top();
            MaxHeap.pop();
        }
    }
};

int main(){
    vector<int> vec({1,3,2,4,6,8,7,5,0});
    // HeapSort h;
    // h.Heap_sort(vec);

    STLHeap sh;
    sh.STL_Heap_sort(vec);
    for(int num : vec){
        cout << num << " ";
    }
    return 0;
}

template<typename type>class MaxHeap{
public:
   MaxHeap(){
      _heapSize = 0;
      heapVec.reserve(sizeof(type) * 88890);//88888
   }
	
	void add(type node){
		heapVec.push_back(node);
		int selfIdx = heapVec.size() - 1;
		int fatherIdx = (selfIdx - 1) / 2;
		while (fatherIdx >= 0 && selfIdx != 0){
			if (heapVec[fatherIdx] > node) break;
			heapVec[selfIdx] = heapVec[fatherIdx];
			selfIdx = fatherIdx;
			fatherIdx = (fatherIdx - 1) / 2;
		}
		heapVec[selfIdx] = node;
      ++_heapSize;
	}
	
	void pop(){
		if (!heapVec.empty()){
			heapVec[0] = heapVec[heapVec.size() - 1];
			heapVec.pop_back();
		}
		adjust();
      --_heapSize;
	}
   void fullAdd(type& tmp){
      heapVec[0] = tmp;
      adjust();
   }
	void adjust(){
		if (heapVec.empty()) return;
		type root = heapVec[0];
		int fatherIdx = 0;//从根节点开始
		int childIndex = fatherIdx * 2 + 1;//左孩子
		while (childIndex < heapVec.size()){
			if (childIndex + 1 < heapVec.size() && heapVec[childIndex] < heapVec[childIndex + 1])
				childIndex++;//左孩子小于右孩子，选择右孩子
			if (heapVec[childIndex] < root)
				break;
			heapVec[fatherIdx] = heapVec[childIndex];
			fatherIdx = childIndex;
			childIndex = childIndex * 2 + 1;
		}
		heapVec[fatherIdx] = root;
	}
   type top(){
      if(heapVec.empty()) {
         cerr << "heap null" << endl;
         exit(1);
      }
      return heapVec[0];
   }
   int heapSize(){
      return _heapSize;
   }

// private:
   int _heapSize;
	vector<type> heapVec;
};
