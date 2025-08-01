#include<bits/stdc++.h>
using namespace std;

vector<int> arr;


int main(){
    int n, r_sum;
    cin >> n >> r_sum;
    
    arr.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int count = 0;

    vector<int> pref(n+1,0);
    pref[0] = 0;

    for(int i=1;i<n;i++){
        pref[i] = pref[i] + arr[i-1];
    }
    int l =0, sum =0;
    int i =0;
    while(i != n){
        sum += arr[i];
        while(sum > r_sum){
            sum -= arr[l];
            l++;
        }
        count++;
        i++;
    }

    cout << count ;
    
}