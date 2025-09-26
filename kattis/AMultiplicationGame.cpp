#include <bits/stdc++.h>
using namespace std;

string winner(long long n) {
    bool player = true;
    while (n > 1) {
        long long d = n / (player ? 9 : 2);
        long long m = n % (player ? 9 : 2);
        n = (m ? d + 1 : d);
        player = !player;
    }
    return player ? "Ollie wins." : "Stan wins.";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        long long n = stoll(line);
        cout << winner(n) << "\n";
    }

    return 0;
}
