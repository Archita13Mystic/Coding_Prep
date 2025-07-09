#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string snew="";
    // if(s.length()%2==0){
    //     snew=s[s.length()/2-1];
    // }
    // else
    // snew=s[s.length()/2];
    int l=s.length();
    if(l % 2 == 0){
        int right=l-1;
        int left=0;
        for(int i=0;i<l/2;i++){
            snew=s[right]+snew;
            snew=s[left]+snew;
            right--;
            left++;
        }
    }
    else{
        
        int right=l-1;
        int left=0;
        for(int i=0;i<l/2;i++){
            snew=s[left]+snew;
            snew=s[right]+snew;
            left++;
            right--;
        }
        snew=s[l/2]+snew;
    }

    cout << snew << endl;

}