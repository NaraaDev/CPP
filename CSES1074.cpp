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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    if (n == 2)
    {
        cout << nums[1] - nums[0] << '\n';
        return;
    }

    ll ans = 0, ans1 = 0;
    int mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        ans += abs(nums[i] - nums[mid]);
        ans1 += abs(nums[i] - nums[mid - 1]);
    }

    cout << min(ans, ans1);
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
Hoorhon nomio Zarimdaa aashtai nomio nebula
*/
