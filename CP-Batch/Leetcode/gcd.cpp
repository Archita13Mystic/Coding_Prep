#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}


int main(){
    int n,m;
    cin >> n >> m;
    cout << gcd(min(n,m),max(n,m)) << endl;
    
}