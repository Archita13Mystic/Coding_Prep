#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-i+1;j++){
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }

    int c;
    cin >> c;
    vector<vector<int>> q(2,<vector<int>>(c));
    for(int i=0;i<c;i++){

    }
    for(int i)

}