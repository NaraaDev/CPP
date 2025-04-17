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

const int MAX_N = 1e5 + 10;

vector<vector<int> >nodes(MAX_N, vector<int> ());
vector<vector<int> >back_edges(MAX_N, vector<int> ());


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<int> dp(n + 1, 0);
    vector<int> in_degree(n + 1, 0);

    dp[1] = 1;

    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        nodes[a].pb(b);
        back_edges[b].pb(a);
        in_degree[b]++;
    }

    queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] == 0) { q.push(i); }
	}

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int child: nodes[node]) {
            in_degree[child]--;
            if(in_degree[child] == 0) q.push(child);
        }
        for (int prev : back_edges[node]) {
			dp[node] = (dp[node] + dp[prev]) % MOD;
		}
    }
   

    cout << (dp[n] % MOD);

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/