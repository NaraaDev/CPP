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

int findMex(int row, int col, int n, vector<vector<int> > grid) {
    int mex = 0;

    vector<int> v;

    for(int i = 1; i <= col; i++) {
        v.push_back(grid[row][i]);
    }

    for(int i = 1; i <= row; i++) {
        v.push_back(grid[i][col]);
    }
    sort(v.begin(), v.end());
    int pos = 0, ss = v.size();

    while(pos < ss) {
        if(v[pos] == mex) mex++;
        pos++;
    }
    return mex;
}

void uCan() {
    int n;
    cin >> n;
    vector<vector<int> > grid(n + 1, vector<int> (n + 1, -1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                grid[i][j] = 0;
                continue;
            } 
            if(j == 1) {
                grid[i][j] = i - 1;
                continue;
            }
            if(i == 1) {
                grid[i][j] = j - 1;
                continue;
            }


        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            if(i == j) continue;
            grid[i][j] = findMex(i, j, n, grid);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
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
*/