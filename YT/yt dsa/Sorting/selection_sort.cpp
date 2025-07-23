#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> select(n,0);

    for(int i=0;i<n;i++){
        cin >> select[i];
    }

    //selection sort

    for(int i=0;i<n;i++){
    int m=INT_MAX;
        for(int j=i;j<n;j++){
            if(select[j] < m)
            swap(m, select[j]);
        }
        select[i] = m;
    }

    for(int i=0;i<n;i++)
    cout << select[i] << " ";

    return 0;

}