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
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int now = 0;
            int ci = i, cj = j;
            while (ci >= 0 && ci < n && cj >= 0 && cj < m)
            {
                now += a[ci][cj];
                ci--;
                cj--;
            }
            ci = i, cj = j;
            while (ci >= 0 && ci < n && cj >= 0 && cj < m)
            {
                now += a[ci][cj];
                ci++;
                cj--;
            }
            ci = i, cj = j;
            while (ci >= 0 && ci < n && cj >= 0 && cj < m)
            {
                now += a[ci][cj];
                ci--;
                cj++;
            }
            ci = i, cj = j;
            while (ci >= 0 && ci < n && cj >= 0 && cj < m)
            {
                now += a[ci][cj];
                ci++;
                cj++;
            }
            now -= a[i][j] * 3;
            mx = max(mx, now);
        }
    }
    cout << mx << endl;
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
