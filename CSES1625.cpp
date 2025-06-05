#include <bits/stdc++.h>
using namespace std;

string path;
bool visited[7][7];
int ans = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

bool is_valid(int x, int y) {
    return 0 <= x && x < 7 && 0 <= y && y < 7 && !visited[x][y];
}

void dfs(int x, int y, int step) {
    if (x == 6 && y == 0) {
        if (step == 48) ans++;
        return;
    }

    
    if (step >= 48) return;
    if ((is_valid(x+1, y) == false && is_valid(x-1, y) == false &&
         is_valid(x, y+1) && is_valid(x, y-1)) ||
        (is_valid(x, y+1) == false && is_valid(x, y-1) == false &&
         is_valid(x+1, y) && is_valid(x-1, y))) {
        return;
    }

    visited[x][y] = true;

    if (path[step] != '?') {
        int i = find(dir, dir+4, path[step]) - dir;
        int nx = x + dx[i], ny = y + dy[i];
        if (is_valid(nx, ny)) dfs(nx, ny, step + 1);
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny)) dfs(nx, ny, step + 1);
        }
    }

    visited[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> path;
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
*/
