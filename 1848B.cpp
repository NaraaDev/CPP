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
    int n, k;
    cin >> n >> k;

    vector<int> last(k + 1, 0);
    vector<int> mx1(k + 1, 0), mx2(k + 1, 0);

    auto add = [&](int color, int gap)
    {
        if (gap >= mx1[color])
        {
            mx2[color] = mx1[color];
            mx1[color] = gap;
        }
        else if (gap > mx2[color])
        {
            mx2[color] = gap;
        }
    };

    for (int i = 1; i <= n; i++)
    {
        int color;
        cin >> color;

        add(color, i - last[color] - 1);
        last[color] = i;
    }

    int ans = n;

    for (int color = 1; color <= k; color++)
    {
        add(color, n - last[color]);

        ans = min(ans, max(mx1[color] / 2, mx2[color]));
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
