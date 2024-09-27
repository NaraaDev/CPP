#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if(a == 1) {
            if((n - 1) % b == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            bool ans = false;
            ll t = 1;
            while(t <= n) {
                if(t % b == n % b) {
                    ans = true;
                    break;
                }
                t *= a;
            }

            cout << (ans ? "YES\n" :"NO\n");
            
        }
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
Yes
No
Yes
No
Yes
*/