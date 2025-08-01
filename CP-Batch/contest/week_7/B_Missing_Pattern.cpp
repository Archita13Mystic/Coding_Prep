#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<vector<char>> latin(3,vector<char>(3,'0'));
        int row,col;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >>latin[i][j];
                if(latin[i][j] == '?')
                row = i;
                col = j;
            }
        }
        for(int i=0;i<3;i++){
            if(i == col) continue;
            
        }
    }  
}