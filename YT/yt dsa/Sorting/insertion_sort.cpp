#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n,0);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }

    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}