#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution{
public:
    vector<int> getLeastNumbers(vector<int>& input, int k) {
        if(input.size() == 0 || k == 0 || k > input.size()) return {};
        priority_queue<int, vector<int>, less<int>> que;
        for(int i = 0; i < input.size(); ++i){
            if(que.size() < k) que.push(input[i]);
            else if(que.top() > input[i]){
                que.pop();
                que.push(input[i]);
            }
        }
        vector<int> res;
        for(int i = 0; i < k; ++i){
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& input, int k) {
        if(input.size() == 0 || k == 0 || input.size() < k) return {};
        return quick_sort(input, 0, input.size() - 1, k);
    }
    vector<int> quick_sort(vector<int>& vec, int left, int right, int k){
        int j = partition(vec, left, right);
        if(j == k - 1) {
            quick_sort(vec, left, k - 1);
            return vector<int> (vec.begin(), vec.begin() + k);
        }
        return j >= k ? quick_sort(vec, left, j - 1, k) : quick_sort(vec, j + 1, right, k);
    }
    void quick_sort(vector<int>& vec, int left, int right){
        if(left >= right) return;
        int j = partition(vec, left, right);
        quick_sort(vec, left, j - 1);
        quick_sort(vec, j + 1, right);
    }
    int partition(vector<int>& vec, int left, int right){
        int pivot = vec[left];
        int i = left, j = right + 1;
        while(i < j){
            while(++i <= right && vec[i] < pivot);
            while(--j >= left && vec[j] > pivot);
            if(i >= j) break;
            swap(vec[i], vec[j]);
        }
        swap(vec[left], vec[j]);
        return j;
    }
};

int main(){
    Solution2 s;
    vector<int> vec({4,5,1,6,2,7,3,8});
    vector<int> res = s.getLeastNumbers(vec, 4);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}