#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back


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
    int n;
    cin >> n;

    int totalNum = 1 << n; // 2^n
    vector<int> ans;
    for(int i = 0; i < totalNum; i++) {
        ans.pb(i ^ (i >> 1));
    }

    for(int i = 0; i < ans.size(); i++) {
        for(int j = n - 1; j >= 0; j--) {
            cout << ((ans[i] >> j) & 1);
        }
        cout << '\n';
    }

}

/*
RILY <3
NEVER GIVE UP!!!
00
01
11
10
*/