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

    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<int> left, right;

    if (n % 2 == 0)
    {
        bool isLeft = true;
        for (int i = 1; i <= n / 2; i++)
        {
            if (isLeft)
            {
                left.pb(i);
                left.pb(n - i + 1);
            }
            else
            {
                right.pb(i);
                right.pb(n - i + 1);
            }
            isLeft = !isLeft;
        }
    }
    else
    {
        bool isLeft = true;
        for (int i = 1; i <= n / 2; i++)
        {
            if (isLeft)
            {
                left.pb(i);
                left.pb(n - i);
            }
            else
            {
                right.pb(i);
                right.pb(n - i);
            }
            isLeft = !isLeft;
        }

        if (left.size() >= right.size())
        {
            right.pb(n);
        }
        else
        {
            left.pb(n);
        }
    }

    cout << left.size() << '\n';
    for (int i = 0; i < left.size(); i++)
        cout << left[i] << ' ';

    cout << '\n'
         << right.size() << '\n';
    for (int i = 0; i < right.size(); i++)
        cout << right[i] << ' ';
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
