#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i + 1;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        ll target = x - a[i].F;
        int left = i + 1, right = n - 1;

        while (left < right) {
            ll sum = a[left].F + a[right].F;

            if (sum == target) {
                cout << a[i].S << ' ' << a[left].S << ' ' << a[right].S << endl;
                return 0;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

/*
RILY <3
NEVER GIVE UP!!!
*/
