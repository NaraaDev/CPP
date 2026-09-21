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

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    vector<int> odd, even;

    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            odd.pb(i);
        else
            even.pb(i);
    }

    for (int i : even)
        cout << i << ' ';
    for (int i : odd)
        cout << i << ' ';
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
*/
