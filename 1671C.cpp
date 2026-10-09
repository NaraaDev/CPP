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

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    ll ans = 0;

    for (int i = 1; i < n; i++)
        nums[i] += nums[i - 1];

    for (int i = 0; i < n; i++)
    {

        ll left = 1, right = 1e9;
        ll maxx = 0;
        while (left <= right)
        {
            ll mid = (left + right) / 2;
            if (nums[i] + (mid - 1) * (i + 1) > x)
                right = mid - 1;
            else
            {
                left = mid + 1;
                maxx = max(maxx, mid);
            }
        }
        ans += maxx;
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
