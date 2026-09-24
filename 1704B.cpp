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

    ll n, x;
    cin >> n >> x;

    vector<ll> nums(n);

    for (auto &p : nums)
        cin >> p;

    ll l = 0, r = 0;
    ll ans = 0;
    l = x > nums[0] ? x : nums[0] - x;
    r = nums[0] + x;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] - x > r || nums[i] + x < l)
        {
            ans++;
            l = x > nums[i] ? 0 : nums[i] - x;
            r = nums[i] + x;
        }
        else
        {
            l = max(x > nums[i] ? 0 : nums[i] - x, l);
            r = min(nums[i] + x, r);
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
