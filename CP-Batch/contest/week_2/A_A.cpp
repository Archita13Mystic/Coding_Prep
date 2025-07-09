#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }     
    int c = 1;
    vector<vector<int>> heaps;
    

    for (int val : v) {
        bool inserted = false;

        for (auto& heap : heaps) {
            if (val <= heap.front()) {
                heap.push_back(val);
                push_heap(heap.begin(), heap.end());
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            vector<int> newHeap = {val};
            make_heap(newHeap.begin(), newHeap.end());
            heaps.push_back(newHeap);
        }
    }
    cout << heaps.size() << endl;
}