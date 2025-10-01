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

struct Range {int l, r, id;};

struct Fenwick {
    int n; vector<int> bit;
    Fenwick(int n = 0): n(n), bit(n + 1, 0) {}
    
    void add(int i, int v = 1) {
        for(; i <= n; i += i & -i)
            bit[i] += v;
    }

    int sum(int i) {
        int s = 0;
        for(; i > 0; i -= i & -i)
            s += bit[i];
        
        return s;
    }

    int rangeSum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

};

void uCan() {

    int n;
    cin >> n;
    vector<Range> nums(n);
    vector<int> rs;
    for(int i = 0; i < n; i++) {
        cin >> nums[i].l >> nums[i].r;
        nums[i].id = i;
        rs.pb(nums[i].r);
    }
        
    sort(rs.begin(), rs.end());
    rs.erase(unique(rs.begin(), rs.end()), rs.end());

    auto getR = [&](int x) {
        return int(lower_bound(rs.begin(), rs.end(), x) - rs.begin()) + 1;
    };

    for(auto &p: nums) {
        p.r = getR(p.r);
    }

    vector<int> contains(n, 0), contained(n, 0);

    {
        auto b = nums;
        sort(b.begin(), b.end(), [](const Range &x, const Range &y) {
            if(x.l != y.l) return x.l < y.l;
            return x.r > y.r;
        });

        Fenwick bit((int)rs.size());

        for(auto &p: b) {
            int total_prev = bit.sum(rs.size());
            int less_than_r = bit.sum(p.r - 1);

            contained[p.id] = total_prev - less_than_r;
            bit.add(p.r, 1);
        }

    }

    {
        auto b = nums;

        sort(b.begin(), b.end(), [](const Range &x, const Range &y) {
            if(x.l != y.l) return x.l > y.l;
            return x.r < y.r;
        });

        Fenwick bit((int)(rs.size()));

        for(auto &p: b) {
            contains[p.id] = bit.sum(p.r);
            bit.add(p.r, 1);
        }

    }

    for(int i = 0; i < n; i++) {
        cout << contains[i] << ' ';
    }

    cout << '\n';

    for(int i = 0; i < n; i++)
        cout << contained[i] << ' ';
    

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