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

    int n, m;
    cin >> n >> m;

    vector<int> ans;

    vector<pair<vector<int>, int>> unee(n);

    for (int i = 0; i < n; i++)
    {
        unee[i].first.resize(m);
        unee[i].second = i + 1;

        for (int j = 0; j < m; j++)
            cin >> unee[i].first[j];

        sort(unee[i].first.begin(), unee[i].first.end());
    }
    sort(unee.begin(), unee.end());
    int card = -1;
    int pos = 0;
    int hed = 0;
    int round = n * m;
    while (round--)
    {
        pos %= n;
        if (unee[pos].first[hed] <= card)
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            card = unee[pos].first[hed];
            pos++;
            if (pos == n)
                hed++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << unee[i].second << ' ';
    }
    cout << '\n';
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
*/
