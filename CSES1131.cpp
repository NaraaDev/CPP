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

vector<vector<int> > nodes(2e5 + 5);
int cnt[200005];

void dfs(int node, int parent) {
    vector<int> childs;

    for(int child: nodes[node]) {
        if(child != parent) {
            cnt[child] = cnt[node] + 1;
            dfs(child, node);
            
        }
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int a, b;

    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        nodes[a].pb(b);
        nodes[b].pb(a);
    }

    cnt[1] = 0;
    dfs(1, 0);

    int maxDist = 0, node = 1;

    for(int i = 1; i <= n; i++) {
        if(cnt[i] > maxDist) {
            maxDist = cnt[i];
            node = i;
        }
    }


    for(int i = 1; i <= n; i++)
        cnt[i] = 0;
    
    dfs(node, 0);

    maxDist = 0;

    for(int i = 1; i <= n; i++)
        maxDist = max(maxDist, cnt[i]);
    
    cout << maxDist;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/