#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n,vector<char>(m,'a'));

        int m = -1;
        int row = -1;
        int count = 0;
        for(int i=0;i<n;i++){
            m = -1;
            count = 0;
            for(int j=0;j<m;j++){
                cin >> grid[i][j];
                if(grid[i][j] == '#'){
                    count++;
                }
                if(m < count){
                    row= i;
                    m = count;
                }
            }
        }
        for(int i = 0;i<m ;i ++){
            if(count == 1)
            
        }
    }
}