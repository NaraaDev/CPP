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
    int ans = 1;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    map<int, int> cnt;
    int cur = 0, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (cnt.find(nums[i]) == cnt.end())
        {
            cnt[nums[i]] = i + 1;
            cur++;
        }
        else
        {
            if (cnt[nums[i]] < last)
            {
                cnt[nums[i]] = i + 1;
                cur++;
            }
            else
            {
                last = cnt[nums[i]] + 1;
                cnt[nums[i]] = i + 1;
            }
            cur = (i + 1) - last + 1;
        }

        ans = max(ans, cur);
    }

    cout << ans << '\n';
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
