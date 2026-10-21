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
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    s = "L" + s + "L";

    int pos = 0;

    while (pos < n + 1)
    {
        if (s[pos] == 'C')
        {
            cout << "NO\n";
            return;
        }

        if (s[pos] == 'L')
        {
            if (pos + m >= n + 1)
            {
                cout << "YES\n";
                return;
            }

            int nextLog = -1;

            for (int j = pos + m; j > pos; j--)
            {
                if (s[j] == 'L')
                {
                    nextLog = j;
                    break;
                }
            }

            if (nextLog != -1)
                pos = nextLog;
            else
                pos += m;
        }
        else
        {
            if (k == 0)
            {
                cout << "NO\n";
                return;
            }

            pos++;
            k--;
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
