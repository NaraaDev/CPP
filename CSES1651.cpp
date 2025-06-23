#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 5;

ll tree[4 * N];
ll lazy[4 * N];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        int tm = (tl + tr) / 2;
        tree[v * 2] += lazy[v] * (tm - tl + 1);
        lazy[v * 2] += lazy[v];
        tree[v * 2 + 1] += lazy[v] * (tr - tm);
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
}

void update(int idx, int tl, int tr, int l, int r, ll add) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[idx] += add * (tr - tl + 1);
        lazy[idx] += add;
    } else {
        push(idx, tl, tr);
        int tm = (tl + tr) / 2;
        update(idx * 2, tl, tm, l, min(r, tm), add);
        update(idx * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

ll query(int idx, int tl, int tr, int pos) {
    if (tl == tr)
        return tree[idx];
    push(idx, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return query(idx * 2, tl, tm, pos);
    else
        return query(idx * 2 + 1, tm + 1, tr, pos);
}

void uCan() {
    int n, q;
    cin >> n >> q;

    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(a, 1, 0, n - 1);

    while (q--) {
        int k;
        cin >> k;
        if (k == 2) {
            int l;
            cin >> l;
            cout << query(1, 0, n - 1, l - 1) << '\n';
        } else {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, b - 1, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        uCan();
    }

    return 0;
}
/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
*/