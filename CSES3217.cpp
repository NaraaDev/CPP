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

pair<int, int> moves[8] = {
    {1,2}, {1, -2}, {-1, 2}, {-1, -2},
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;


    vector<vector<int> > matrix(n + 1, vector<int> (n + 1, INT_MAX));

    queue<pair<int, int > > pq;
    matrix[1][1] = 0;
    
    pq.push({1, 1});
    while(!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();
        
        
        for(int i = 0; i < 8; i++) {
            int dx = x + moves[i].first;
            int dy = y + moves[i].second;
            
            if(dx >= 1 && dx <= n && dy >= 1 && dy <= n && matrix[dx][dy] > matrix[x][y] + 1) {
                matrix[dx][dy] = matrix[x][y] + 1;
                pq.push(mp(dx, dy));
            }
        }

    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << matrix[i][j] << ' ';
        }
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
*/