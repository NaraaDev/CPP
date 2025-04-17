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

const int MAX_N = 2e5 + 5;

vector<vector<int> > nodes(MAX_N, vector<int >() );

void bfs(int node, vector<int> &dist) {
    queue<int> q;

    q.push(node);
    dist[node] = 0;

    vector<bool> visited(MAX_N, false);
    visited[node] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        
        for(int child : nodes[node]) {
            if(!visited[child]) {
                visited[child] = true;
                dist[child] = dist[node] + 1;
                q.push(child);
            }
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
    
    vector<int > dist(n + 1, 0);
    vector<int> disa(n + 1, 0);

    bfs(1, dist);
    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    bfs(u, dist);
    int v = max_element(dist.begin(), dist.end()) - dist.begin();    
    bfs(u, dist);
    bfs(v, disa);

    for(int i = 1; i <= n; i++) {
        cout << max(dist[i], disa[i]) << ' ';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/