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
const int N = 1e6;
vector<vector<int>> dividers(N + 1, vector<int>());

void solve()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> removed(n + 1, false);

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] == '1')
                break;
            if (!removed[j])
            {
                removed[j] = true;
                ans += i;
            }
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
