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
    int n;
    cin >> n;

    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        while (x % 2 == 0)
        {
            cnt++;
            x /= 2;
        }
    }

    if (cnt >= n)
    {
        cout << 0 << '\n';
        return;
    }

    vector<int> gains;

    for (int i = 2; i <= n; i++)
    {
        int x = i;
        int add = 0;

        while (x % 2 == 0)
        {
            add++;
            x /= 2;
        }

        if (add > 0)
            gains.pb(add);
    }

    sort(gains.rbegin(), gains.rend());

    int ans = 0;

    for (int add : gains)
    {
        cnt += add;
        ans++;

        if (cnt >= n)
        {
            cout << ans << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
