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

    string s;
    cin >> s;

    int ans = n + 1;

    for (int c = 0; c < 26; c++)
    {
        int l = 0, r = n - 1, cnt = 0;

        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else if (s[l] == char('a' + c))
            {
                cnt++;
                l++;
            }
            else if (s[r] == char('a' + c))
            {
                cnt++, r--;
            }
            else
            {
                cnt = n + 1;
                break;
            }
        }
        ans = min(ans, cnt);
    }

    cout << (ans == n + 1 ? -1 : ans) << '\n';
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
