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

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n): n(n), tree(4 * n, 0) {};

    void build(vector<int> &a, int v, int l, int r) {
        if(l == r) {
            tree[v] = a[l];
        } else {
            int mid = (l + r) / 2;
            build(a, v * 2, l, mid);
            build(a, v * 2 + 1, mid + 1, r);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if(tl == tr) {
            tree[v] = new_val;
        } else {
            int mid = (tl + tr) / 2;
            if(pos <= mid) update(v * 2, tl, mid, pos, new_val);
            else update(v * 2 + 1, mid + 1, tr, pos, new_val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int x) {
        if(tree[v] < x) return -1;
        if(tl == tr) return tl;
        int mid = (tl + tr) / 2;
        if(tree[v * 2] >= x) return query(v * 2, tl, mid, x);
        else return query(v * 2 + 1, mid + 1, tr, x);
    }
};

void uCan() {

    int n, m;
    cin >> n >> m;

    vector<int> rooms(n);

    for(int i = 0; i < n; i++)
        cin >> rooms[i];
    
    SegTree st(n);

    st.build(rooms, 1, 0, n - 1);


    while(m--) {
        int x;
        cin >> x;
        int idx = st.query(1, 0, n - 1, x);
        if(idx == -1) {
            cout << 0 << ' ';
        } else {
            cout << idx + 1 << ' ';
            rooms[idx] -= x;
            st.update(1, 0, n - 1, idx, rooms[idx]);
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