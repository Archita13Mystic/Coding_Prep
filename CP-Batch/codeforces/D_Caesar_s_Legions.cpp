#include<bits/stdc++.h>
using namespace std;
int k1,k2,f,h;
int MOD = 1e8;
int dp[101][101][11][11];

int men(int F, int H, int K1, int K2){

    if(F == f && H == h) return 1;


    if(dp[F][H][K1][K2] != -1) return dp[F][H][K1][K2];

    int ways = 0;
    if(K1 < k1 && F < f){
        ways += men(F+1,H,K1+1,0);
        ways %= MOD;
    }
    if(K2 < k2 && H < h){
        ways += men(F,H+1,0,K2+1);
        ways %= MOD;
    }
    return dp[F][H][K1][K2] = ways;

}

int main(){

    cin >> f >> h >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << men(0,0,0,0);
}