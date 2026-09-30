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

    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }

    sort(a.rbegin(), a.rend());

    vector<int> x(n + 1, 0);
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        int distance = i / 2 + 1;
        int coordinate = (i % 2 == 0 ? distance : -distance);

        x[a[i].ss] = coordinate;
        total += 2LL * a[i].ff * distance;
    }

    cout << total << '\n';

    for (int i = 0; i <= n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
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
