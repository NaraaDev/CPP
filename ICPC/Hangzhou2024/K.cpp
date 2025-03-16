#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int a[n * m];

        for(int i = 0; i < n * m; i++)
            cin >> a[i];

        
        vector<int> v(n, m);
        int ans = 0;
        for(int i = 0; i < n * m; i++) {
            v[(a[i] - 1) / m]--;
            ans++;
            if(v[(a[i] - 1) / m] <= k) {
                break;
            }
        }

        cout << max(m,ans) << '\n';

    }

}
/*
7
5
3
*/