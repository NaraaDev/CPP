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

    vector<pair<int, int>> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i].ff >> nums[i].ss;

    bool can = true;

    for (int i = 0; i < n; i++)
        if (nums[i].ff < nums[i].ss)
            can = false;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        if (x > nums[i].ff || y > nums[i].ss || abs(x - nums[i].ff) < abs(y - nums[i].ss))
        {
            can = false;
        }
        x = max(nums[i].ff, x);
        y = max(nums[i].ss, y);
    }

    cout << (can ? "YES\n" : "NO\n");
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
