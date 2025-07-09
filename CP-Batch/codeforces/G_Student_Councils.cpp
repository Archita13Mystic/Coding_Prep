#include<bits/stdc++.h>
using namespace std;


int main(){
    int k;
    cin >> k;
    int n;
    cin >> n;

    vector<long long> a(n);

    long long sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }

    long long l=1,r=sum, ans=0;
    while(l<=r){
        long long mid = (l+r)/2;

        long long tot=0;
        for(int i=0;i<n;i++){
            tot+=min(a[i],mid);
        }
        if(tot >= mid*k){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans << "\n";
    return 0;

}