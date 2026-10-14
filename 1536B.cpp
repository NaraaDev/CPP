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
    string s;
    cin >> n >> s;

    for (int len = 1; len <= 3; len++)
    {
        set<string> seen;

        for (int i = 0; i + len <= n; i++)
        {
            seen.insert(s.substr(i, len));
        }

        int total = 1;
        for (int i = 0; i < len; i++)
        {
            total *= 26;
        }

        for (int num = 0; num < total; num++)
        {
            string cur(len, 'a');
            int x = num;

            for (int i = len - 1; i >= 0; i--)
            {
                cur[i] = char('a' + x % 26);
                x /= 26;
            }

            if (seen.find(cur) == seen.end())
            {
                cout << cur << '\n';
                return;
            }
        }
    }
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
