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

    SegTree(int n): n(n), tree(4 * (n + 1), 0) {};

    void build(vector<int> &a, int l, int r, int v) {
        if(l == r) {
            tree[v] = a[l] > 0;
        } else {
            int mid = (l + r) / 2;
            build(a, l, mid, v * 2);
            build(a, mid + 1, r, v * 2 + 1);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int v, int l, int r, int pos, int val) {
        if(l == r) {
            tree[v] = val > 0;
        } else {
            int mid = (l + r) / 2;
            if(pos <= mid) update(v * 2, l, mid, pos, val);
            else update(v * 2 + 1, mid + 1, r, pos, val);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    int query(int v, int l, int r) {
        if(tree[v] > 0) return -1;
        if(l == r) return l;
        int mid = (l + r) / 2;
        if(tree[v * 2] == 0) return query(v * 2, l, mid);
        else return query(v * 2 + 1, mid + 1, r);
    }

};

void uCan() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    vector<int> mexx(N, 0);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    SegTree st(N);
    for(int i = 0; i < k; i++) {
        if(nums[i] <= N - 1) {
            mexx[nums[i]]++;
        }
        
    }

    st.build(mexx, 0, N - 1, 1);

    int pos = st.query(1, 0, N - 1);
    cout << pos << ' ';
    
    for(int i = k; i < n; i++) {
        int out = nums[i - k];
        int in = nums[i];
        if(in <= N - 1 && out <= N - 1) {
            mexx[out]--;
            st.update(1, 0, N - 1, out, mexx[out]);
            mexx[in]++;
            st.update(1, 0, N - 1, in, mexx[in]);
        }
       

        pos = st.query(1, 0, N - 1);
        cout << pos << ' ';
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