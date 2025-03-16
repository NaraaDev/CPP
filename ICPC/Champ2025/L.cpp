#include <bits/stdc++.h>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n, p;
    cin >> r >> c >> n >> p;

    int grid[r][c];
    set<int> s;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    map<int, vector<int>> neigh;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != 0) {
                int person = grid[i][j];

                if (j + 1 < c && grid[i][j + 1] != 0) 
                    neigh[person].push_back(grid[i][j + 1]);
                if (j - 1 >= 0 && grid[i][j - 1] != 0) 
                    neigh[person].push_back(grid[i][j - 1]);
                if (i + 1 < r && grid[i + 1][j] != 0) 
                    neigh[person].push_back(grid[i + 1][j]);
                if (i - 1 >= 0 && grid[i - 1][j] != 0) 
                    neigh[person].push_back(grid[i - 1][j]);
            }
        }
    }

    int cnt = 0;

    while (p > 0) {
        if (neigh.find(p) != neigh.end()) {
            for (int i = 0; i < neigh[p].size(); i++) {
                int neighbor = neigh[p][i];
                if (neighbor + cnt <= n) {
                    s.insert(neighbor + cnt);
                }
            }
        }
        cnt++;
        p--;
    }

    cout << s.size() << "/" << (n - 1);
}
