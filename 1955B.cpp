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

    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> nums(n * n);

    for (int i = 0; i < n * n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<vector<ll>> ans(n, vector<ll>(n, -1));

    map<ll, int> ms;

    for (auto p : nums)
        ms[p]++;

    ans[0][0] = nums[0];
    ms[nums[0]]--;
    if (ms[nums[0]] == 0)
    {
        ms.erase(ms.find(nums[0]));
    }

    for (int i = 1; i < n; i++)
    {
        if (ms.find(ans[i - 1][0] + c) == ms.end())
        {
            cout << "NO\n";
            return;
        }
        else
        {
            ans[i][0] = ans[i - 1][0] + c;
            ms[ans[i][0]]--;
            if (ms[ans[i][0]] == 0)
                ms.erase(ms.find(ans[i][0]));
        }

        if (ms.find(ans[0][i - 1] + d) == ms.end())
        {
            cout << "NO\n";
            return;
        }
        else
        {
            ans[0][i] = ans[0][i - 1] + d;
            ms[ans[0][i]]--;
            if (ms[ans[0][i]] == 0)
                ms.erase(ms.find(ans[0][i]));
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((ans[i - 1][j] + c != ans[i][j - 1] + d) || (ms.find(ans[i - 1][j] + c) == ms.end()))
            {
                cout << "NO\n";
                return;
            }
            else
            {
                ans[i][j] = ans[i - 1][j] + c;
                ms[ans[i][j]]--;
                if (ms[ans[i][j]] == 0)
                {
                    ms.erase(ms.find(ans[i][j]));
                }
            }
        }
    }

    cout << "YES\n";
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
