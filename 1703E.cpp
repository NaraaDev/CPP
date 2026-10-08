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

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 1;
            if (grid[j][n - 1 - i] == grid[i][j])
                cnt++;
            if (grid[n - 1 - i][n - 1 - j] == grid[i][j])
                cnt++;
            if (grid[n - 1 - j][i] == grid[i][j])
                cnt++;
            if (cnt >= 2)
            {
                if (grid[j][n - 1 - i] != grid[i][j])
                    grid[j][n - 1 - i] = grid[i][j];

                if (grid[n - 1 - i][n - 1 - j] != grid[i][j])
                    grid[n - 1 - i][n - 1 - j] = grid[i][j];

                if (grid[n - 1 - j][i] != grid[i][j])
                    grid[n - 1 - j][i] = grid[i][j];

                ans += 4 - cnt;
            }
            else
            {
                ans += cnt;
                grid[i][j] = grid[j][n - 1 - i];
            }
        }
    }

    cout << ans << '\n';
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
