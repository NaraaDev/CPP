
#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;

    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ms.insert(a);
    }
    int ans = 0;

    while (!ms.empty())
    {
        int big = *prev(ms.end());
        ms.erase(prev(ms.end()));

        int slot = x - big;
        auto it = ms.lower_bound(slot);
        if (ms.empty())
        {
            ans++;
            break;
        }
        if (it == ms.begin() && *it > slot)
        {
            ans++;
            continue;
        }

        if (*it > slot || it == ms.end())
            --it;
        slot -= *it;
        ms.erase(it);
        ans++;
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
        solve();

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
