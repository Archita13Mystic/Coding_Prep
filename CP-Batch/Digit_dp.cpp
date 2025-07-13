#include<bits/stdc++.h>
using namespace std;

int f(int ind, int tb, int sum){
    int mx = 9;
    if(tb) mx = s[ind] - '0';
    ans = 0;
    for(int i=0;i<=mx;i++){
        if(i<=mx){
            ans+= f(ind+1, 0 , sum+i;
        }
        else{
            if(tb) ans+=f(ind+1,1,sum+i);
            else ans+=f(ind+1,0,sum+i);
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    return f(0,0,0);     
}