#include <bits/stdc++.h>
using namespace std;

void printer(const vector<char> &lst, int m) {
    int ind = m - 1;
    while (ind >= 0 && lst[ind] == ' ') ind--;
    for (int i = 0; i <= ind; i++) cout << lst[i];
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool first = true;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        cin.ignore(); 

        if (first) first = false;
        else cout << "\n";

        vector<vector<char>> mat;
        int max_width = 0;

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            max_width = max(max_width, (int)line.size());
            mat.push_back(vector<char>(line.begin(), line.end()));
        }

        for (int i = 0; i < n; i++) {
            while ((int)mat[i].size() < max_width) mat[i].push_back(' ');
        }

        vector<vector<char>> mat2(max_width, vector<char>(n, ' '));
        for (int x = 0; x < max_width; x++) {
            for (int y = 0; y < n; y++) {
                char c = mat[y][x];
                if (c == '-') mat2[x][n - y - 1] = '|';
                else if (c == '|') mat2[x][n - y - 1] = '-';
                else mat2[x][n - y - 1] = c;
            }
        }

        for (const auto &row : mat2) printer(row, n);
    }

    return 0;
}