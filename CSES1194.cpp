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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char direction(int i) {
    if(i == 0) return 'D';
    if(i == 1) return 'U';
    if(i == 2) return 'R';
    return 'L';
}

char lab[1005][1005];
int maps[1005][1005];

bool canMove(int i, int j, int n, int m) {
    return j < m && j >= 0 && i >= 0 && i < n && lab[i][j] == '.';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    
    int startX, startY;

    queue<pair<int,int> > bfs;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
            maps[i][j] = -1;
            if(lab[i][j] == 'A') {
                startX = i;
                startY = j;
                maps[i][j] = 0;
            }
            if(lab[i][j] == 'M') 
                bfs.push(mp(i, j));
            
        }


    bfs.push(mp(startX, startY));
    maps[startX][startY] = -1;
    while(!bfs.empty()) {
        pair<int,int> now = bfs.front();
        bfs.pop();
        if(lab[now.F][now.S] == 'A' && (now.F == 0 || now.F == n - 1 || now.S == 0 || now.S == m - 1)) {
            cout << "YES\n";
            string ans = "";
            int to = maps[now.F][now.S];
            while(to != -1) {
                ans += direction(to);
                now.F -= dx[to];
                now.S -= dy[to];
                to = maps[now.F][now.S];
            }

            reverse(ans.begin(), ans.end());
            cout << ans.length() << '\n';
            cout << ans;
            return 0;
        } else {
            for(int i = 0; i < 4; i++) {
                int toX = now.F + dx[i];
                int toY = now.S + dy[i];
                if(canMove(toX, toY, n, m)) {
                    lab[toX][toY]=lab[now.F][now.S];
                    if(lab[toX][toY] == 'A') 
                        maps[toX][toY] = i;
                    bfs.push(mp(toX, toY));
                }

            }
        }
    }   
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++)
    //         cout << maps[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << "NO";   

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
YES
5
RRDDR
*/