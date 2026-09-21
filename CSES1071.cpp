#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b)
{

    ll res = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve()
{

    ll y, x;
    cin >> y >> x;
    ll ans = max(y, x) * max(y, x);
    if (x == 1 && y == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if ((x == 1 && y % 2 == 0) || (y == 1 && x % 2 == 1))
    {
        cout << ans << '\n';
        return;
    }

    if (y % 2 == 0 && y >= x)
    {
        cout << ans - (x - 1) << '\n';
    }
    else if (x % 2 == 1 && x >= y)
    {
        cout << ans - (y - 1) << '\n';
    }
    else if (y % 2 == 1 && y >= x)
    {
        cout << ans - y - (y - x - 1) << '\n';
    }
    else
    {
        cout << ans - x - (x - y - 1) << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/
