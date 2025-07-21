#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    unordered_map<int, int> count;
    int x;
    cin >> x;

    for(int i=0;i<s.length();i++){
        count[s[i]-'a']++;
    }
    
    vector<char> v;
    int t = x;
    while(x--){
        char d;
        cin >> d;
        v.push_back(d);
    }
    
    for(int i=0;i<t;i++){
        cout << count[v[i]-'a'] << "\n";
    }
    return 0;
}