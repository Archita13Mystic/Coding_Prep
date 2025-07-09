#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin >> n >> x;
    vector<long long> p(n,0);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }     

    int count=0;
    for(int i=0;i<n-1;i++){
        long long sum=p[i];
        for(int j=i+1;i<n;j++){
            sum+=p[j];
            if(sum == x){
                count++;
                break;
            }
        }
    }
    cout << count << "\n";

}