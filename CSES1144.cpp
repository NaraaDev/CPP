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

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n): n(n), bit(n + 1, 0){}

    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i)
            bit[i] += delta;
    }

    int sum (int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }


    int sumRange(int l, int r) {
        return sum(r) - sum(l - 1);
    }


};

void uCan() {

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    vector<int> all;

    for(auto &p: nums) {
        cin >> p;
    }
        

    vector<pair<char,pair<int,int>>> queries(q);
    for(int i = 0; i < n; i++) {
        all.pb(nums[i]);
    }

    char c;
    int y, x;
    for(int i = 0; i < q; i++) {
        cin >> c >> x >> y;
        queries[i] = {c, {x, y}};
        if(c == '!') all.pb(y);
        else all.pb(x), all.pb(y);
    }

    // Coordinate Compression
    sort(all.begin(), all.end());

    all.erase(unique(all.begin(), all.end()), all.end());

    auto get_idx = [&](int val) {
        return lower_bound(all.begin(), all.end(), val) - all.begin();
    };

    BIT bit (all.size());

    for(int i = 0; i < n; i++)
        bit.add(get_idx(nums[i]), 1);
    

    for(auto &p: queries) {
        c = p.F;
        x = p.S.F;
        y = p.S.S;

        if(c == '!') {
            int idx = x - 1;
            bit.add(get_idx(nums[idx]), -1);
            nums[idx] = y;
            bit.add(get_idx(nums[idx]), 1);
        } else {
            int l = get_idx(x);
            int r = get_idx(y);
            cout << bit.sumRange(l, r) << '\n';
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