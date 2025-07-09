#include<bits/stdc++.h>
using namespace std;


void print(int line){
    if(line==0) return;
    cout << "* ";
    print(line-1);
}

void pattern(int n,int line){
    if(n == line+1){
        return;
    }
    print(line);
    cout << "\n";
    pattern(n,line-1);
}



int main(){
    pattern(5,5);
    return 0;
}