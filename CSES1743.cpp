#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26);
    for (char c : s) freq[c - 'A']++;

    for (int f : freq) {
        if (f > (n + 1) / 2) {
            cout << -1 << '\n';
            return 0;
        }
    }

    string result = "";
    char last = '?';

    for (int i = 0; i < n; ++i) {
        bool placed = false;
        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            char ch = 'A' + c;
            if (ch == last) continue;

            freq[c]--;
            bool can_finish = true;
            int max_allowed = (n - i - 1 + 1) / 2;
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > max_allowed) {
                    can_finish = false;
                    break;
                }
            }
            if (can_finish) {
                result += ch;
                last = ch;
                placed = true;
                break;
            }
            freq[c]++;
        }

        if (!placed) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << result << '\n';
    return 0;
}
