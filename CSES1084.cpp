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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> ap(n), money(m);

    for (int i = 0; i < n; i++)
        cin >> ap[i];

    for (int i = 0; i < m; i++)
        cin >> money[i];

    sort(ap.begin(), ap.end());
    sort(money.begin(), money.end());

    int ans = 0;
    int last = 0;
    for (int i = 0; i < m; i++)
    {
        auto it = lower_bound(ap.begin() + last, ap.end(), money[i] - k);
        if (it == ap.end())
            break;

        if (*it - k <= money[i])
        {
            last = (it - ap.begin()) + 1;
            ans++;
        }
    }

    cout << ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

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
Hoorhon nomio Zarimdaa aashtai nomio nebula
*/
