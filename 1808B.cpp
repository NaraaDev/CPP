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

    ll ans = 0;

    vector<vector<int>> nums(n, vector<int>(m));
    vector<map<int, int>> v(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
            v[j][nums[i][j]]++;
        }

    for (int i = 0; i < m; i++)
    {
        ll sum = 0;
        ll cnt = 0;

        for (auto [x, freq] : v[i])
        {
            ans += (1LL * x * cnt - sum) * freq;
            sum += 1LL * x * freq;
            cnt += freq;
        }
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
*/
