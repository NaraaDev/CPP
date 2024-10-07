#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin >> n >> x;

    ll a[n];

    for(int i = 0 ;i < n; i++ )
        cin >> a[i];
    int ans = 0;
    int left = 0;
    ll sums = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) {
            left = i + 1;
            sums = 0;
        } else
            sums += a[i];
        
        while(sums >= x && left <= i) {
            if(sums == x) ans++;
            sums -= a[left++];
        }

        while(sums <= 0 && left <= i && x >= 0) {
            if(sums == x) ans++;
                sums -= a[left++];
        }
        
    }


    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/