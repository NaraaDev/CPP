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

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n): n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sum(int idx) {
        int s = 0;
        for(; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }

    int range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

};

struct Query {
    int l, r, idx;
};

void uCan() {

    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<Query> queries(q);

    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), [](auto &x, auto&y) {
        return x.r < y.r;
    });

    Fenwick ft(n);

    map<int, int> last;
    vector<int> ans(q);

    int curr_r = 0;

    for(auto &qr: queries) {
        while(curr_r < qr.r) {
            curr_r++;
            int val = nums[curr_r];
            if(last.find(val) != last.end()) {
                ft.add(last[val], -1);
            }
            ft.add(curr_r, 1);
            last[val] = curr_r;
        }
        ans[qr.idx] = ft.range_sum(qr.l, qr.r);
    }

    for(auto x: ans)
        cout << x << '\n';

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