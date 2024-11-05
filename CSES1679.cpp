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

const int N = 1e5 + 5;

vector<vector<int> > nodes(N);



bool isHasCycle(int n) {
    
    vector<int> degree(n + 1, 0);

    queue<int> q;

    int visited = 0;

    for(int u = 1; u <= n; u++) {
        for(auto v: nodes[u]) {
            degree[v]++;
        }
    }

    for(int u = 1; u <= n; u++) {
        if(degree[u] == 0) {
            q.push(u);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;

        for(auto v: nodes[u]) {
            degree[v]--;
            if(degree[v] == 0)
                q.push(v);
        }

    }

    return n != visited;

}

vector<int> ans;
bool vis[N];
void dfs(int node) {
    for(auto v: nodes[node]) {
        if(!vis[v]) {
            vis[v] = true;
        }
    }
}
int cnt[N];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].pb(b);
        cnt[b]++;
    }

    // if(isHasCycle(n))  {
    //     cout << "IMPOSSIBLE";
    //     return 0;
    // }
    // for(int i = 1; i <= n; i++) {
    //     if(nodes[i].size() != 0 && !vis[i]) {
    //         vis[i] = true;
    //         ans.pb(i);
    //         dfs(i);
    //     }
    // }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) q.push(i);
    }


    int ans = n;
    vector<int> res;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        res.pb(u);
        ans--;
        for(int v: nodes[u]) {
            cnt[v]--;
            if(cnt[v] == 0)
                q.push(v);
        }

    }

    if(ans) {
        cout << "IMPOSSIBLE";
    } else {
        for(int i = 0; i < n; i++)
            cout << res[i] << (" \n")[i==n-1];
    }

    // for(int i: ans)
    //     cout << i << ' ';

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/