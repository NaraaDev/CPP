#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll tree[N * 4];

void build(int idx, int l, int r, int a[]) {
    if(l == r) tree[idx] = a[l];
    else {
        int mid = (l + r) / 2;
        build(idx * 2, l, mid, a);
        build(idx * 2 + 1, mid + 1, r, a);
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

int query(int idx, int l, int r, int tl, int tr) {
    if(l > tr || r < tl) {
        return INT_MAX;
    }
    if(l >= tl && r <= tr) {
        return tree[idx];
    }

    int mid = (l + r) / 2;
    return min(query(idx * 2, l, mid, tl, tr), query(idx * 2 + 1, mid + 1, r, tl, tr));
}

void uCan() {

    int n, q;
    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    build(1, 0, n - 1, a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << query(1, 0, n - 1, l, r) << '\n';
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;
    while(t--) {
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