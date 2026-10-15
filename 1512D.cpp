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

    vector<ll> b(n + 2);
    vector<ll> prefix(n + 3, 0);
    for (int i = 0; i < n + 2; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    for (int i = 0; i < n + 2; i++)
        prefix[i + 1] = prefix[i] + b[i];

    int pos = -1;
    if (prefix[n] == b[n])
    {
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i <= n; i++)
    {
        if (prefix[n + 1] - b[n + 1] == b[i])
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << -1 << '\n';
    else
    {
        for (int i = 0; i <= n; i++)
            if (i != pos)
                cout << b[i] << ' ';
        cout << '\n';
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
