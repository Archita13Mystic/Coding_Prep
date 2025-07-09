#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin >> n >> m;
        int max1=INT_MIN;
        int mx[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mx[i][j];
                if(mx[i][j] > max1) 
                max1=mx[i][j];
            }
        }
        vector<int> rowcount(n,0), colcount(m,0);
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mx[i][j] == max1){
                    rowcount[i]++;
                    colcount[j]++;
                    count++;
                }
            }
        }
            bool flag = false;
            int tot;
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    tot=rowcount[r] + colcount[c] - (mx[r][c] == max1);
                    if(tot == count){
                    flag =true;
                    break;
                    }
                }
            }
            if(!flag) 
            cout << max1 << endl;
            else 
            cout << max1-1 << endl;
        
    }
    return 0;
}