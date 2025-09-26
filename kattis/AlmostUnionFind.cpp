#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) {
        vector<set<int>> sets(a);
        vector<int> set_map(a);
        for (int i = 0; i < a; i++) {
            sets[i].insert(i);
            set_map[i] = i;
        }

        for (int cmd_idx = 0; cmd_idx < b; cmd_idx++) {
            int k;
            cin >> k; 
            vector<int> lst;

            if (k == 1 || k == 2) {
                int i, j;
                cin >> i >> j;
                i--; j--; 
                if (k == 1) {
                    if (set_map[i] != set_map[j]) {
                        int si = set_map[i], sj = set_map[j];
                        if (sets[si].size() > sets[sj].size())
                            swap(si, sj);
                        for (int e : sets[si]) {
                            set_map[e] = sj;
                            sets[sj].insert(e);
                        }
                        sets[si].clear();
                    }
                } else {
                    if (set_map[i] != set_map[j]) {
                        sets[set_map[i]].erase(i);
                        sets[set_map[j]].insert(i);
                        set_map[i] = set_map[j];
                    }
                }
            } else if (k == 3) {
                int i;
                cin >> i;
                i--; 
                int sz = sets[set_map[i]].size();
                long long s = 0;
                for (int e : sets[set_map[i]]) s += e + 1;
                cout << sz << " " << s << "\n";
            }
        }
    }

    return 0;
}
