#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    cin >> v[i];

    bool s = false;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(v[j] > v[j+1]){
            swap(v[j], v[j+1]);
            s = true;
            }
        }
        if(!s) {
            cout << " NO sorting" << "\n";
            break;
        }
    }
    for(int i=0;i<n;i++) cout << v[i] << " ";
}