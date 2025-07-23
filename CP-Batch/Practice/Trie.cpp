#include<bits/stdc++.h>
using namespace std;

struct node{
    int child[26];
    bool is_end = false;
    void init(){
        fill(child, child+26,-1);
    }
};

struct trie{
    vector <node>triee;
    void init(){
        node f;
        f.init();
        triee.push_back(f);
    }
    void insert(string& s){
        int v=0;
        for(char c:s){
            int i= c-'a';
            if(triee[v].child[i] == -1){
                triee[v].child[i] = triee.size();
                node temp;
                temp.init();
                triee.push_back(temp);
            }
            v = triee[v].child[i];
        }
        triee[v].is_end = true;
    }

    bool search(string& s){
        int v = 0;
        for(char c: s){
            int i = c - 'a';
            if(triee[v].child[i] == -1){
                return false;
            }
            v = triee[v].child[i];
        }
        return triee[v].is_end;
    }

    void remove(string& s){
        if(search(s)){
            int v = 0;
            for(char c: s){
                int i = c - 'a';
                if(triee[v].child[i] == -1){
                    return;
                }
                v = triee[v].child[i];
            }
            triee[v].is_end = false;
        }

    }


};


int main(){
    int n;
    cin >> n;
    trie t;
    vector<string> s(n);
    t.init();
    for(int i=0;i<n;i++){
        cin >> s[i];
        
        t.insert(s[i]);
    }

    string st;
    cin >> st;
    cout << t.search(st) << "\n";
    string k;
    cin >> k;
    t.remove(k);
    
    cout << "successfully removed " << t.search(k) << "\n";

}