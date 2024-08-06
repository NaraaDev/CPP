#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;


int teams[200005];
vector<bool> vis(200005);
vector<vector<int> > nodes(200005);


void dfs(vector<vector<int> > &nodes, int node, int team) {
    vis[node] = true;
    teams[node] = team;
    for(int i: nodes[node]) {
        if(!vis[i]) 
            dfs(nodes, i, team == 1 ? 2 : 1);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;


    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].pb(b);
        nodes[b].pb(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i])
            dfs(nodes, i, 1);
    }

    bool isImpossible = true;
   

    for(int i = 1; i <= n; i++) {
        for(int node: nodes[i]) {
            if(teams[node] == teams[i]) {
                isImpossible = false;
                break;
            }
        }
        if(!isImpossible) break;
    }

    if(!isImpossible) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cout << teams[i] << ' ';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
1 2 2 1 2
*/