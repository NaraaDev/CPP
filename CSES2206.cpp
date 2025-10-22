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

struct Segtree {
    int n;
    vector<ll> tree;

    Segtree(int n): n(n), tree(n * 4, 0) {}

    void update(int I, ll V, int i, int l, int r) {
        if(l == r) {
            tree[i] = V;
            return;
        }
        
        int m = (l + r) / 2;

        if(I <= m) update(I, V, i * 2, l, m);
        else update(I, V, i * 2 + 1, m + 1, r);

        tree[i] = min(tree[i * 2 + 1], tree[i * 2]);

    }

    ll query(int L, int R, int i, int l, int r) {
        if(L <= l && r <= R) {
            return tree[i];
        }
        if(R < l || L > r) return LLONG_MAX;

        int m = (l + r) / 2;
        return min(query(L, R, i * 2, l, m), query(L, R, i * 2 + 1, m + 1, r));
    }

};

void uCan() {

    int n, q;
    cin >> n >> q;
    
    vector<ll> nums(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    Segtree up(n), down(n);
    
    for(int i = 1; i <= n; i++) {
        down.update(i, nums[i] - i, 1, 1, n );
        up.update(i, nums[i] + i, 1, 1, n);
    }
    

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            ll k, x;
            cin >> k >> x;
            nums[k] = x;
            down.update(k, nums[k] - k, 1, 1, n);
            up.update(k, nums[k] + k, 1, 1, n);
        } else {
            int k;
            cin >> k;
            ll D = down.query(1, k, 1, 1, n) + k;
            ll U = up.query(k + 1, n,1,  1, n) - k;

            cout << min(D, U) << '\n';
        }
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
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/