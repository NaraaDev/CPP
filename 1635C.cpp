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

struct Points
{
    ll x, y, z;
};

void solve()
{

    int n;
    cin >> n;

    vector<ll> nums(n);

    for (ll i = 0; i < n; i++)
        cin >> nums[i];

    pair<ll, ll> y, z;
    y.first = nums[n - 2];
    y.second = n - 1;
    z.second = n;
    z.first = nums[n - 1];

    vector<Points> ans;
    for (int i = n - 3; i >= 0; i--)
    {
        if (y.first > z.first)
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            if (nums[i] > nums[i + 1])
            {
                ans.pb({i + 1, y.second, z.second});
            }
            nums[i] = min(nums[i], y.first - z.first);
            if (y.first > nums[i])
            {
                y.first = nums[i];
                y.second = i + 1;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].z << '\n';
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
