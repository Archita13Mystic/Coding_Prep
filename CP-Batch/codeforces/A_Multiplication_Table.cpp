#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,b;
    cin >> n >> b;

    int p,q;
    int count = 0;
    for(int i=1;i*i<=b;i++){
        if(b%i == 0) 
        {
            p=i;
            q=b/i;
            if(p <= n && q <= n) count++;
        }
    }
    cout << count << endl;
}