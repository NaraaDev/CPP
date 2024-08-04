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
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
 
    vector<vector<int> > computers(n + 1);
 
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a, b);
 
        computers[a].pb(b);
        computers[b].pb(a);
    }
 
    queue<pair<int,int > >q;
    
    q.push({1, 0});
    int size[n + 1];
 
    for(int i = 1; i <= n; i++)
        size[i] = 0;
    
    while(!q.empty()) {
        int com = q.front().F;
        int val = q.front().S;
        q.pop();
        for(int i = 0; i < computers[com].size(); i++) {
            int to = computers[com][i];
            if(to != 1 && size[to] == 0 || size[to] > val + 1) {
                size[to] = val + 1;
                if(to == n) {
                    size[to] = val + 1;
                }
                q.push({to, val + 1});
            }
            
        }
 
    }
 
    if(size[n] == 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << size[n] + 1 << '\n';

        queue<int> backRoute;
        vector<int> ans({n});

        backRoute.push(n);

        while(!backRoute.empty()) {
            int tt = backRoute.front();
            backRoute.pop();
            for(int i = 0; i < computers[tt].size(); i++) {
                int to = computers[tt][i];
                if(size[to] + 1 == size[tt]) {
                    ans.pb(to);
                    backRoute.push(to);
                    break;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        for(int i: ans){
            cout << i << ' ';
        }

    }
 
    return 0;
 
}
 
/*
RILY <3
NEVER GIVE UP!!!
*/