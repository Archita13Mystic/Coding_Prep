#include<bits/stdc++.h>
using namespace std;
int n;
    int jump(int i,vector<int>& dp,vector<int>& h){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int left = abs(h[i] - h[i-1]) + jump(i-1, dp, h);
        int right = INT_MAX;
        if(i > 1)
        right = abs(h[i] - h[i-2]) + jump(i-2, dp, h);
        return dp[i] = min(left,right);
    }

    int main() {

        cin >> n;
        
        vector<int> heights(n,0);

        for(int i=0;i<n;i++) cin >> heights[i];

        vector<int> dp (heights.size()+1,-1);
        cout << jump(n-1, dp, heights);
    }
