#include<bits/stdc++.h>
using namespace std;
int n;

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int>temp;
    int right = mid+1;
    int left = low;
    while(low <= mid && right <= high){
        if(arr[low] <= arr[right]){
            temp.push_back(arr[low]);
            low++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
        while(low<=mid){
            temp.push_back(arr[low]);
            low++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=left;i<=high;i++){
            arr[i] = temp[i-left];
        }
}

void mergesort(vector<int>& arr, int low, int high){

    if(low >= high)
    return;

        int mid  = low+(high-low)/2;

        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
}

int main(){
    cin >> n;
    
    vector<int> arr(n,0);
    for(int i =0;i < n;i++){
        cin >> arr[i];
    }
    mergesort(arr, 0, n-1);
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}