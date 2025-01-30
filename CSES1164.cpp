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
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<pair<int,int>, int>> v(n);
 
    int ans[n];
 
    for(int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
 
    sort(v.begin(), v.end());
 
    int room = 0;
 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
 
    for(int i = 0; i < n; i++) {
        if(pq.empty() || pq.top().first >= v[i].first.first) {
            room++;
            pq.push(mp(v[i].first.second, room));
            ans[v[i].second] = room;
        } else {
            pair<int,int> p = pq.top();
            pq.pop();
            pq.push(mp(v[i].first.second, p.second));
            ans[v[i].second] = p.second;
        }
    }
 
    cout << room << '\n';
 
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
 
}
 
/*
RILY <3
NEVER GIVE UP!!!
*/