#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct SegmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, INF);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tree[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, lx, mid);
        } else {
            update(i, v, 2 * x + 2, mid, rx);
        }
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return INF;  
        if (lx >= l && rx <= r) return tree[x];  
        int mid = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, mid);
        int right = query(l, r, 2 * x + 2, mid, rx);
        return min(left, right);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    SegmentTree seg;
    seg.init(n);
    seg.build(a);

    while (m--) {
        int type, b, c;
        cin >> type >> b >> c;
        if (type == 1) {
            seg.update(b, c); 
        } else {
            cout << seg.query(b, c) << '\n';  
        }
    }

    return 0;
}
