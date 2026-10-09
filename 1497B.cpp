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
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m, 0);

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cnt[x % m]++;
    }

    int ans = (cnt[0] > 0);

    for (int r = 1; r <= m / 2; r++)
    {
        int x = cnt[r];
        int y = cnt[m - r];

        if (r == m - r)
            ans += (x > 0);
        else if (x == 0 || y == 0)
            ans += x + y;
        else
            ans += max(1, abs(x - y));
    }

    cout << ans << '\n';
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
