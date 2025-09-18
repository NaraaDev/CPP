#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

constexpr int MAX_SIDE = 1000;
int tree_pref[MAX_SIDE + 1][MAX_SIDE + 1];
int forest[MAX_SIDE + 1][MAX_SIDE + 1];

void uCan() {

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            forest[i + 1][j + 1] += c == '*';
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] + tree_pref[i][j - 1] - tree_pref[i - 1][j - 1];
        }
    }

    while(q--) {
        int from_row, to_row, from_col, to_col;
        cin >> from_row >> from_col >> to_row >> to_col;

        cout << tree_pref[to_row][to_col] - tree_pref[from_row - 1][to_col] - 
        tree_pref[to_row][from_col - 1] + tree_pref[from_row - 1][from_col - 1] << '\n';

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;
    while(t--) {
        uCan();
    }

    return 0;

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