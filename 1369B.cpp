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

    while (true)
    {

        string newS = "";

        vector<bool> deleted(s.length(), false);

        int pos = -1;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '0')
            {
                pos = i + 1;
                break;
            }
        }

        if (pos == -1)
            break;

        int lastZero = -1;

        for (int i = pos + 1; i < s.length(); i++)
            if (s[i] == '0')
                lastZero = i;

        for (int i = pos + 1; i <= lastZero; i++)
            deleted[i] = true;
        lastZero = n;
        for (int i = 0; i < pos; i++)
        {
            if (s[i] == '1')
            {
                lastZero = i;
                break;
            }
        }
        for (int i = pos - 1; i >= lastZero; i--)
            deleted[i] = true;

        for (int i = 0; i < s.length(); i++)
            if (!deleted[i])
                newS += s[i];

        s = newS;
    }

    cout << s << '\n';
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
