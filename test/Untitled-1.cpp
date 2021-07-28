#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;

int main(){
    int k;
    cin >> k;
    int kids = pow(2, k);
    vector<int> vec(kids);
    unordered_map<int, int> umap;
    for(int i = 0; i < kids; ++i){
        cin >> vec[i];
        umap[vec[i]] = i;
    }
    
    while(kids > 1){
        vector<int> tmp;
        for(int i = 0; i < kids; i += 2){
            tmp.push_back(min(vec[i], vec[i + 1]));
        }
        kids /= 2;
        if(kids == 1){
            cout << umap[tmp[0]] << endl;
            return 0;
        }
        vec.clear();
        for(int i = 0; i < kids; i += 2){
            vec.push_back(max(tmp[i], tmp[i + 1]));
        }
        kids /= 2;
    }
    cout << umap[vec[0]] << endl;
    return 0;
}