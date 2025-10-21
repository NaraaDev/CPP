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

struct Node {
    ll sum, pref, suff, ans;
};

Node tree[N * 4];

Node combine(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

Node make_node(int val) {
    Node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}



void build (vector<ll> &nums, int v, int l, int r) {
    if(l == r) {
        tree[v] = make_node(nums[l]);
    } else {
        int mid = (l + r) / 2;
        build(nums, v * 2, l, mid);
        build(nums, v * 2 + 1, mid + 1, r);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int v, int l, int r, int pos, ll val) {
    if(l == r) {
        tree[v] = make_node(val);
    } else {
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(v * 2, l, mid, pos, val);
        else
            update(v * 2 + 1, mid + 1, r, pos, val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_node(0);
    if (l == tl && r == tr) 
        return tree[v];
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)), 
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void uCan() {

    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    build(nums, 1, 0, n - 1);

    while(q--) {
        ll u, k;
        cin >> k >> u;
        update(1, 0, n - 1, k - 1, u);
        Node temp = query(1, 0, n - 1, 0, n - 1);
        cout << temp.ans << '\n';
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