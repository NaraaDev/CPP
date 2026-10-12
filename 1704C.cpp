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
    ll n;
    int m;
    cin >> n >> m;

    vector<ll> a(m);
    for (auto &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    vector<ll> gaps;

    for (int i = 1; i < m; i++)
        gaps.pb(a[i] - a[i - 1] - 1);

    gaps.pb(n - a.back() + a.front() - 1);

    sort(gaps.rbegin(), gaps.rend());

    ll days = 0;
    ll saved = 0;

    for (ll gap : gaps)
    {
        ll remaining = gap - 2 * days;

        if (remaining <= 0)
            break;

        if (remaining <= 2)
        {
            saved++;
            days++;
        }
        else
        {
            saved += remaining - 1;
            days += 2;
        }
    }

    cout << n - saved << '\n';
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
