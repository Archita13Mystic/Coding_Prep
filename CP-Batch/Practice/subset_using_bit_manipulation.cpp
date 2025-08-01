#include <iostream>
#include <vector>
using namespace std;

int main() {
    int d;
    cin >> d;
    vector<int> vec(d,0);
    for(int i=0;i<d;i++){
        cin >> vec[i];
    }
    int n = vec.size();
    int total = 1 << n; 

    for (int mask = 0; mask < total; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cout << vec[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}



