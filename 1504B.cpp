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

    string a, b;
    cin >> a >> b;

    vector<int> zeros(n, 0), ones(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            zeros[i] = zeros[i - 1];
            ones[i] = ones[i - 1];
        }

        if (a[i] == '0')
            zeros[i]++;
        else
            ones[i]++;
    }

    bool flipped = false;

    for (int i = n - 1; i >= 0; i--)
    {
        int current = a[i] - '0';

        if (flipped)
            current = 1 - current;

        if (current != b[i] - '0')
        {
            if (zeros[i] != ones[i])
            {
                cout << "NO\n";
                return;
            }

            flipped = !flipped;
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
