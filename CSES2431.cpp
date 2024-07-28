#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;

    while(q--) {
        ll k;
        cin >> k;
        ll len = 1, count = 9, start = 1;

        while(k > len * count) {
            k -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        start += (k - 1) / len;

        string number = to_string(start);
        cout << number[(k - 1) % len] << '\n';

    }

}

/*
RILY <3
NEVER GIVE UP!!!
7
4
1
*/