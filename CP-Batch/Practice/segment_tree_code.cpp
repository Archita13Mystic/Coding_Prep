#include <bits/stdc++.h>
using namespace std;

int ne = 0; // neutral element(here 0 as the query is sum)

struct SegmentTree {
    vector<int> tree;
    int size;

    int merge(int a, int b) {
        return a + b;
    }

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void build(vector<int>& a, int lx, int rx, int x) {
        if (lx == rx) {
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, lx, mid, 2 * x + 1);
        build(a, mid + 1, rx, 2 * x + 2);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int>& a) {
        build(a, 0, size - 1, 0);
    }

    void update(int i, int v, int lx, int rx, int x) {
        if (lx == rx) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i <= mid) {
            update(i, v, lx, mid, 2 * x + 1);
        } else {
            update(i, v, mid + 1, rx, 2 * x + 2);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, size - 1, 0);
    }

    int query(int l, int r, int lx, int rx, int x){
        if( lx > r || rx < l) return ne;
        if(lx >= l && rx <= r){
            return tree[x];
        }
        int mid = (lx+rx) >> 1;
        int left = query(l , r, lx ,mid, 2*x+1);
        int right = query(l, r, mid+1, rx, 2*x+2);
        return merge(left, right);
    }

    int query(int l, int r){
        return query(l, r, 0, size - 1, 0);
    }
    
};

int main() {
    SegmentTree seg;
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];

    seg.init(arr.size());
    seg.build(arr);

    cout << seg.query(1, 3) << "\n";

    seg.update(2, 10);

    cout << seg.query(1, 3) << "\n";

    return 0;
}
