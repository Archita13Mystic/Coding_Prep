#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int val = stoi(s);
        int root = sqrt(val);

        if (root * root != val) {
            cout << -1 << endl;
            continue;
        }
        bool found = false;
        for (int a = 0; a <= root; ++a) {
            int b = root - a;
            if (a >= 0 && b >= 0) {
                cout << a << " " << b << endl;
                found = true;
                break;
            }
        }   

        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}
