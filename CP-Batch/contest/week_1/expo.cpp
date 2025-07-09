#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    while(tc--){
        long long a,b,c;
        cin >> a >> b >> c;
        long long r = (long long) pow(a,b);
        long long d = (long long) pow(r,c);
        long long e = (long long) pow(10,9);
        long long f = d % (e+7);
        cout << f << endl;
    }
}