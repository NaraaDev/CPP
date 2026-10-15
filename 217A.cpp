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

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].ff >> v[i].ss;

    vector<bool> visited(n, false);

    function<void(int)> dfs = [&](int u)
    {
        visited[u] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                (v[u].ff == v[i].ff || v[u].ss == v[i].ss))
            {
                dfs(i);
            }
        }
    };

    int groups = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            groups++;
            dfs(i);
        }
    }

    cout << groups - 1 << '\n';
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
