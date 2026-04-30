#include<bits/stdc++.h>


#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b) {

    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

struct cmp {
    bool operator()(const pair<int, int> & a, const pair<int, int> &b) const {
        int diffA = a.second - a.first;
        int diffB = b.second - b.first;

        if(diffA != diffB) 
            return diffA > diffB;

        return a.first < b.first;
    }
};

void solve() {

    int n;
    cin >> n;

    if(n == 1) {
        cout << "1\n";
        return;
    }

    if(n == 2) {
        cout << "1 2\n";
        return;
    }

    if(n == 3) {
        cout << "2 1 3\n";
        return;
    }
    vector<int> ans(n, 0);
    
    multiset<pair<int, int>, cmp> ms;

    ms.insert({0, n - 1});
    int cnt = 1;
    while(!ms.empty()) {
        auto it = *ms.begin();
        if(it.second - it.first <= 0) break;
        int diff = it.second - it.first;
        int mid = (it.second + it.first) / 2;
            ans[mid] = cnt++;
            ms.erase(ms.begin());
            ms.insert({it.first, mid - 1});
            ms.insert({mid + 1, it.second});


    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == 0) ans[i] = cnt++;
    }

    for(auto p: ans)
        cout << p << ' ';
    cout << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/