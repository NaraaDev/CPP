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

const int N = 505;

ll routes[N][N];


void Warshall_floyd(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(routes[i][k] != LLONG_MAX && routes[k][j] != LLONG_MAX)
                routes[i][j] = min(routes[i][j], routes[i][k] + routes[k][j]); 
        }
    }
}
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) routes[i][j] = 0;
            else routes[i][j] = LLONG_MAX;
        }
    }

    for(int i = 1; i <= m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        routes[a][b] = min(c, routes[a][b]);
        routes[b][a] = min(c, routes[a][b]);
    }

    Warshall_floyd(n);

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (routes[a][b] == LLONG_MAX ? -1 : routes[a][b]) << '\n';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
5
5
8
-1
3
*/