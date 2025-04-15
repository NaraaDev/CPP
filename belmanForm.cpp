#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
const int MAX_E = 1e5 + 5; // edge-irmeg
const int MAX_V = 1e5 + 5; // Node | vertex -> oroi;
const int INF = INT_MAX;
int d[MAX_V] // minimum cost



ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

struct edge {int from, to, cost};

edge es[MAX_E];

void shortest_path(int s) {
    for(int i = 0; i < MAX_V; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    while(true) {
        bool up = false;
        for(int i = 0; i < MAX_E; i++) {
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                up = true;
            }
        }
        if(!up) break;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/