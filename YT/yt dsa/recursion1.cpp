#include<bits/stdc++.h>
using namespace std;

void name(string str, int n){
    if(n==0) return;
    cout << str << "\n";
    name(str,--n);
}

int main(){
    string s;
    int n;
    cin >> s ;
    cin >> n;
    name(s,n);
    return 0;     
}