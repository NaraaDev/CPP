#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 7;
int n, k, arr[N], leftChild[N], rightChild[N], stackArr[N];
ll res;
int cnt;

bool dfs(int p, int v) {
    if (!p) return true;
    if (leftChild[p] && (arr[leftChild[p]] + v) % (arr[p] + v) != 0) return false;
    if (rightChild[p] && (arr[rightChild[p]] + v) % (arr[p] + v) != 0) return false;
    return dfs(leftChild[p], v) && dfs(rightChild[p], v);
}

void check(int x) {
    if (x < 1 || x > k) return;
    if (dfs(stackArr[1], x)) {
        ++cnt;
        res += x;
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
        leftChild[i] = 0;
        rightChild[i] = 0;
        stackArr[i] = 0;
    }
    int top = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        while (top && arr[stackArr[top]] > arr[i]) top--;
        leftChild[i] = rightChild[stackArr[top]];
        rightChild[stackArr[top]] = i;
        stackArr[++top] = i;
    }

    bool allSame = true;
    for (int i = 2; i <= n; i++) {
        if (arr[i] != arr[1]) {
            allSame = false;
            break;
        }
    }
    if (allSame) {
        cout << k << " " << (1LL + k) * k / 2 << "\n";
        return;
    }

    int gcdDiff = 0, base = 0;
    for (int i = 1; i <= n; i++) {
        if(leftChild[i] && !gcdDiff) {
            gcdDiff = arr[leftChild[i]] - arr[i];
            base = arr[i];
        } else if(rightChild[i] && !gcdDiff){
            gcdDiff = arr[rightChild[i]] - arr[i];
            base = arr[i];
        }
    }

    res = cnt = 0;
    ll i = 1;
    for(i = 1; i * i < gcdDiff; i++) {
        if(gcdDiff % i == 0) {
            check(i - base);
            check(gcdDiff / i - base);
        }
    }

    if(i * i == gcdDiff) check(i - base);

    cout << cnt << " " << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    
    return 0;
}
/*
RILY <3
NEVER GIVE UP!!!
*/