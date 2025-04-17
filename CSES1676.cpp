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

const int MAX_N = 1e5 + 5;

int parent[MAX_N];
int len[MAX_N];

int component = MAX_N;
int ans = -1;

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void dsu(int a, int b) {
    int u = find(a);
    int p = find(b);

    if(u == p) {
        return;
    }
    component--;
    if(len[u] > len[p]) swap(u, p);
    
    len[p] += len[u];
    parent[u] = p;
    ans = max(ans, len[p]);


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    component = n;
    ans = 1;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        len[i] = 1;
    }
        
    int a, b;
    
    while(q--){
        
        cin >> a >> b;
        dsu(a, b);
        cout << component << ' ' << ans << '\n';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/