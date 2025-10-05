#include <bits/stdc++.h>
using namespace std;

int r, c;

struct Slot {
    int i, j;
    int len;
    int dir; 
};

vector<string> grid;
vector<string> words;
vector<vector<int>> wordsPos; 
vector<Slot> slots;
vector<bool> used;
int totalDots = 0;

void printAndExit() {
    for (int i = 0; i < r; ++i) cout << grid[i] << '\n';
    exit(0);
}

void dfs(int si) {
    if (si == (int)slots.size()) {
        printAndExit();
        return;
    }

    Slot s = slots[si];
    int L = s.len;
    if (L >= (int)wordsPos.size()) return;
    for (int idx : wordsPos[L]) {
        if (used[idx]) continue;
        const string &w = words[idx];

        bool ok = true;
        int newly = 0;
        vector<pair<int,int>> filled;
        for (int k = 0; k < L; ++k) {
            int ii = s.i + (s.dir == 1 ? k : 0);
            int jj = s.j + (s.dir == 0 ? k : 0);
            char cell = grid[ii][jj];
            if (cell == '.') {
            } else {
                if (cell != w[k]) { ok = false; break; }
            }
        }
        if (!ok) continue;
        for (int k = 0; k < L; ++k) {
            int ii = s.i + (s.dir == 1 ? k : 0);
            int jj = s.j + (s.dir == 0 ? k : 0);
            if (grid[ii][jj] == '.') {
                grid[ii][jj] = w[k];
                filled.emplace_back(ii,jj);
                newly++;
            }
        }
        used[idx] = true;
        dfs(si + 1);
        used[idx] = false;
        for (auto &p : filled) grid[p.first][p.second] = '.';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> r >> c)) return 0;
    grid.resize(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
        for (char ch : grid[i]) if (ch == '.') totalDots++;
    }

    int n; cin >> n;
    words.resize(n);
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        maxLen = max(maxLen, (int)words[i].size());
    }

    wordsPos.assign(maxLen + 1, {});
    for (int i = 0; i < n; ++i) wordsPos[words[i].size()].push_back(i);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == '#') continue;
            if (j == 0 || grid[i][j-1] == '#') {
                int len = 0;
                int g = j;
                while (g < c && grid[i][g] != '#') { len++; g++; }
                if (len >= 2) slots.push_back({i,j,len,0});
            }
            if (i == 0 || grid[i-1][j] == '#') {
                int len = 0;
                int g = i;
                while (g < r && grid[g][j] != '#') { len++; g++; }
                if (len >= 2) slots.push_back({i,j,len,1});
            }
        }
    }

    vector<int> candCount(slots.size(), 0);
    for (int s = 0; s < (int)slots.size(); ++s) {
        int L = slots[s].len;
        if (L < (int)wordsPos.size()) candCount[s] = (int)wordsPos[L].size();
        else candCount[s] = 0;
    }
    vector<int> order(slots.size());
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int a, int b){
        if (candCount[a] != candCount[b]) return candCount[a] < candCount[b];
        return a < b;
    });
    vector<Slot> slotsOrdered;
    slotsOrdered.reserve(slots.size());
    for (int idx : order) slotsOrdered.push_back(slots[idx]);
    slots.swap(slotsOrdered);

    used.assign(n, false);
    dfs(0);

    return 0;
}
