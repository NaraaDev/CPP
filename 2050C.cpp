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

    string s;
    cin >> s;

    ll sum = 0, sumHigher = 0;
    int len = s.length();
    vector<int> cnt(10, 0);
    for (int i = 0; i < len; i++)
    {
        sum += (s[i] - '0');

        if (s[i] == '2' || s[i] == '3')
            sumHigher += (s[i] - '0') * (s[i] - '0');
        else
            sumHigher += (s[i] - '0');

        cnt[s[i] - '0']++;
    }

    if (sum % 9 == 0 || sumHigher % 9 == 0)
    {
        cout << "YES\n";
        return;
    }

    for (ll i = sum + (9 - (sum % 9)); i <= sumHigher - (sumHigher % 9); i += 9)
    {
        ll rem = i - sum;
        if (rem == cnt[2] * 2 || rem == cnt[3] * 6)
        {
            cout << "YES\n";
            return;
        }

        if (cnt[3] * 6 + cnt[2] * 2 < rem)
            break;

        for (int j = 0; j <= cnt[2]; j++)
        {
            if ((rem - j * 2) % 6 == 0 && (rem - j * 2) / 6 <= cnt[3])
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
