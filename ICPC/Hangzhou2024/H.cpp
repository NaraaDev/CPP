#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

struct tree {
    int l, r;
    int sum;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<tree> v(k);
        vector<int> p(n + 1, -1);
        int maxLen = 0;
        for(int i = 0; i < k; i++) {
            cin >> v[i].l >> v[i].r;
            v[i].sum = v[i].r - v[i].l + 1;
            
            maxLen = max(v[i].sum, maxLen);
            for(int j = v[i].l + 1; j <= v[i].r; j++) {
                p[j] = j - 1;
            }
        }
        int cnt = 0;
        int pos = 0;
        for(int i = 0; i < k; i++) {
            if(maxLen == v[i].sum) {
                pos = v[i].l;
                cnt++;
            }
        }
        p[pos] = 0;
        bool isCan = false;
        for(int i = 0; i < k; i++) {
            if(v[i].l == pos) continue;
            if(v[i].sum >= maxLen - 1) {
                p[v[i].l] = pos;
            }
            else {
                p[v[i].l] = pos + 1;
                isCan = true;
            }
        }
        if(!isCan && cnt > 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(int i = 1; i <= n; i++) {
                cout << p[i] << " \n"[i==n];
            }
        }
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/