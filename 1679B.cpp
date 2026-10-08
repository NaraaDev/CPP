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
    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    ll allValue = 0;
    set<pair<int, int>> st;

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int pos;
            ll x;
            cin >> pos >> x;

            ll oldValue = nums[pos - 1];

            auto it = st.upper_bound({pos, INT_MAX});

            if (it != st.begin())
            {
                --it;
                auto [l, r] = *it;

                if (l <= pos && pos <= r)
                {
                    oldValue = allValue;
                    st.erase(it);

                    if (l < pos)
                        st.insert({l, pos - 1});

                    if (pos < r)
                        st.insert({pos + 1, r});
                }
            }

            sum += x - oldValue;
            nums[pos - 1] = x;
        }
        else
        {
            ll x;
            cin >> x;

            allValue = x;
            sum = x * n;

            st.clear();
            st.insert({1, n});
        }

        cout << sum << '\n';
    }
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
Hoorhon nomio Zarimdaa aashtai nomio
*/
