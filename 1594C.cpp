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
    char c;
    string s;
    cin >> c >> s;

    vector<int> ans;

    bool found = false;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != c)
            found = true;

    if (found)
    {
        if (s[n - 1] == c)
        {
            ans.pb(n);
        }
        else
        {
            vector<int> left;
            vector<int> right;

            for (int i = 0; i < n; i++)
            {
                if (s[i] != c)
                    right.pb(i + 1);
                else
                    left.pb(i + 1);
            }
            int num = 0;

            for (int i = 0; i < left.size(); i++)
            {
                bool can = true;
                for (int j = 0; j < right.size(); j++)
                {
                    if (right[j] % left[i] == 0)
                    {
                        can = false;
                        break;
                    }
                }
                if (can)
                {
                    num = left[i];
                    break;
                }
            }

            if (num == 0)
            {
                ans.pb(n);
                ans.pb(n - 1);
            }
            else
            {
                ans.pb(num);
            }
        }
    }

    int sz = ans.size();

    cout << sz << '\n';

    for (int i = 0; i < sz; i++)
        cout << ans[i] << ' ';
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
