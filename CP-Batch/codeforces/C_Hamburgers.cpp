#include<bits/stdc++.h>
using namespace std;

int main(){
     string s;
     int nb,ns,nc,pb,ps,pc,ru;
     cin >> nb >> ns >> nc;
     cin >> pb >> ps >> pc;
     cin >> ru;
     int cnt[3];
     for(char c: s){
        if(c == 'B') 
        cnt[0]++;
     
        else if(c=='S') 
        cnt[1]++;
        else cnt[2]++;
     }
        


     auto possible = [&] (long long mid){
        long long reqb = max(0ll, mid*cnt[0] - nb);
        long long reqs = max(0ll, mid*cnt[1] - ns);
        long long reqc = max(0ll, mid*cnt[2] - nc);
        long long moneyreq = pb*reqb + ps*reqs + pc*reqc;
        return moneyreq <= ru;
     };

     long long l=0,r=1e12 + 100;

     while(l<=r){
       long long mid=(l+r)/2;
       if(possible(mid)){
        l=mid+1;
       }
       else r=mid-1;
     }
     cout << l-1 << "\n";
     return 0;

}