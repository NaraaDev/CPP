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

    vector<int> nums(n + 2, 0);

    if (n == 1)
    {
        cout << 1 << '\n'
             << 1 << '\n';
        return;
    }

    if (n == 2)
    {
        cout << 1 << '\n'
             << "1 1\n";
        return;
    }

    cout << 2 << '\n';

    for (int i = 2; i <= n + 1; i++)
    {
        if (nums[i] == 1)
            continue;
        for (int j = i + i; j <= n + 1; j += i)
            nums[j] = 1;
    }

    for (int i = 2; i <= n + 1; i++)
        cout << (nums[i] == 0 ? '1' : '2') << ' ';

    cout << '\n';
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
