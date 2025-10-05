#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int arr[N][N];
vector<vector<int>> adj;
vector<int> rowAssign, colAssign;
int test_id;
vector<int> vis;

bool canMatch(int i) {
    if (vis[i] == test_id) return false;
    vis[i] = test_id;
    for (int j : adj[i]) {
        if (colAssign[j] == -1) {
            colAssign[j] = i;
            rowAssign[i] = j;
            return true;
        }
    }
    for (int j : adj[i]) {
        if (canMatch(colAssign[j])) {
            colAssign[j] = i;
            rowAssign[i] = j;
            return true;
        }
    }
    return false;
}

vector<pair<int,int>> maximum_bipartite_matching(int rows, int cols) {
    rowAssign = vector<int>(rows, -1);
    colAssign = vector<int>(cols, -1);
    vis = vector<int>(rows, 0);
    test_id = 0;

    for (int i = 0; i < rows; i++) {
        test_id++;
        canMatch(i);
    }

    vector<pair<int,int>> matches;
    for (int j = 0; j < cols; j++) 
        if (colAssign[j] != -1) matches.push_back({colAssign[j], j});
    return matches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            st.insert(arr[i][j]);
        }

    for (int i = 1; i <= n; i++) {
        if (st.count(i)) continue;
        adj = vector<vector<int>>(n);
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                if (arr[r][c] == 0)
                    adj[r].push_back(c);

        auto matches = maximum_bipartite_matching(n, n);
        for (auto &it : matches)
            arr[it.first][it.second] = i;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " \n"[j+1==n];
        }
    }
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