#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int LOG = 20;
const int MAXN = 2e5 + 5;

int up[MAXN][LOG];
int depth[MAXN];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < LOG; ++i) {
        up[1][i] = -1;
    }

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        up[i][0] = p;

        for (int j = 1; j < LOG; ++j) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
            else
                up[i][j] = -1;
        }
    }

    while (m--) {
        int x, k;
        cin >> x >> k;

        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                x = up[x][i];
                if (x == -1) break;
            }
        }

        cout << x << '\n';
    }
    

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/