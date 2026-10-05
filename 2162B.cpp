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

bool isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;

    while (left <= right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }

    return true;
}

void solve()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    int cntZ = 0, cntO = 0;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        cntZ += (s[i] == '0');
        cntO += (s[i] == '1');
    }

    if (len == cntZ || len == cntO || isPalindrome(s))
    {
        cout << 0 << '\n';
        cout << '\n';
    }
    else
    {
        cout << cntZ << '\n';
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '0')
                cout << i + 1 << ' ';
        }
        cout << '\n';
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
*/
