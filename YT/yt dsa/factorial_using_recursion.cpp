#include<bits/stdc++.h>
using namespace std;

int print(int n){
    if(n==0 || n==1) return 1;
    return n*print(n-1);
}

int main(){
     int n;
     cin >> n;
     int a = print(n);
     cout << a ;
}