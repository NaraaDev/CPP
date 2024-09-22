#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
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

int ans = 0, n , m;
int cats[100005];
vector<bool> used(1e5 + 5);
vector<vector<int> > nodes(1e5 + 5);

void dfs(int cat, int node) {
    if(cat > m) return;
    
    used[node] = true;
    bool isLeaf = true;
    for(int i = 0; i < nodes[node].size(); i++) {
        int to = nodes[node][i];
        int newCat = cats[to] == 1 ? cat + 1 : 0;
        if(!used[to]) {
            isLeaf = false;
            dfs(newCat, to);
        }   
    }
    if(isLeaf) ans++;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> cats[i];
    
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].pb(y);
        nodes[y].pb(x);
    }
    dfs(cats[1], 1);
    cout << ans;    
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/