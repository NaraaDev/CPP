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

    BIT(int n): n(n), bit(n + 1, 0) {}

    void add(int i, int x) {
        for(++i; i <= n; i += i&-i) bit[i] += x;
    }

    int sum(int i) {
        int res = 0;
        for(++i; i > 0; i -= i &-i) {
            res += bit[i];
        }
        return res;
    } 

    int kth(int k) {
        int l = 0, r = n - 1, res = -1;
        // k-р одоо байгаа элемент
        while(l <= r) {
            int m = (l + r) / 2;
            if(sum(m) >= k + 1) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;

    }

};

void uCan() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &p: nums)
        cin >> p;

    BIT bit(n);

    for(int i = 0; i < n; i++) {
        bit.add(i, 1);
    }
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        int idx = bit.kth(--x);
        cout << nums[idx] << ' ';
        bit.add(idx, -1);
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