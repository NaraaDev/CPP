#include<bits/stdc++.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

vector<int> monster(81);
int compute(int u, int v, vector<int> &monster, vector<vector<pair<int, int>>> &nodes, int c) {
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

    vector<unordered_map<int, int>> best(c + 1);
    
    int initial_maxx = monster[u];

    pq.push({initial_maxx, u, 0, initial_maxx});
    while (!pq.empty()) {
        auto [cost, now, sum, maxx] = pq.top();
        pq.pop();

        if (now == v) {
            return cost;
        }
        
        if (best[now].count(maxx) && best[now][maxx] <= sum) continue;
        best[now][maxx] = sum;
        
        for (auto &[to, len] : nodes[now]) {
            int new_sum = sum + len;
            int new_maxx = max(maxx, (int)monster[to]);
            int new_cost = new_sum + new_maxx;
            
            if (!best[to].count(new_maxx) || best[to][new_maxx] > new_sum) {
                pq.push({new_cost, to, new_sum, new_maxx});
            }
        }
    }
    
    return -1;
}

void uCan(int c, int p, int q) {
    vector<vector<pair<int, int>>> nodes(c + 1);
    
    for(int i = 1; i <= c; i++)
        cin >> monster[i];

    int u, v;
    int cost;

    for(int i = 0; i < p; i++) {
        cin >> u >> v >> cost;
        nodes[u].emplace_back(v, cost);
        nodes[v].emplace_back(u, cost);
    }

    vector<vector<int> > ans(c + 1, vector<int> (c + 1, -2));

    while(q--) {
        cin >> u >> v;
        auto key = mp(min(u, v), max(u, v));
        if(u > v) swap(u, v);
        if(ans[u][v] != -2) {
            cout << ans[u][v] << '\n';
        } else {
            int result = compute(u, v, monster, nodes, c);
            ans[u][v] = result;
            cout << result << '\n';
        }
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, p, q;
    int cnt = 1;
    while(true) {
        cin >> c >> p >> q;
        if(c == 0 && p == 0 && q == 0) {
            break;
        }
        cout << cnt << '\n';
        uCan(c, p, q);
        cnt++;
        cout << '\n';
    }

    return 0;
}
/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/