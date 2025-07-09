#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,s;
    cin >> n >> s;

    long long a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    long long sum=0,ans=0,l=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum >= s)
        {
            sum-=a[l];
            ans+=n-i;
            l++;
        }
    }
    cout << ans << endl;


}