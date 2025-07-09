#include<bits/stdc++.h>
using namespace std;

void print(int n,int sum){
    if(n==0){
        
        cout << sum ;
        return;
    }
    sum+=n;
    print(n-1,sum);
}

int main(){
    int n;
    cin >> n;
    print(n, 0);
}