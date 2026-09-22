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

    map<char, int> ms;

    for (char c : s)
        ms[c]++;

    int cnt = 0;

    for (auto i : ms)
    {
        if (i.second & 1)
            cnt++;
    }

    if (cnt > 1)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    string left = "", right = "";

    for (auto i : ms)
    {
        if (i.second & 1)
            continue;
        for (int j = 0; j < i.second / 2; j++)
        {
            left += i.first;
            right += i.first;
        }
    }

    if (cnt & 1)
    {
        for (auto i : ms)
        {
            if (i.second & 1)
            {
                for (int j = 0; j < i.second; j++)
                    left += i.first;
            }
        }
    }

    reverse(right.begin(), right.end());
    string ans = left + right;
    cout << ans;
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
