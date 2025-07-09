#include<bits/stdc++.h>
using namespace std;

void swap1(int* arr, int a,int b){
    if(a>=b) return;
    swap(arr[a],arr[b]);
    a++;b--;
    swap1(arr,a,b);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
     swap1(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}