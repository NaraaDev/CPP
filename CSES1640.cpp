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
    
    int n, x;
    cin >> n >> x;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    map<int, int> m;

    for(int i = 0; i < n; i++) {
        
        if(m.find(x - a[i]) != m.end() && m[x - a[i]] != i + 1) {
            cout << m[x - a[i]] << ' ' << i + 1;
            exit(0);
        }   
        m[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";

}

/*
RILY <3
NEVER GIVE UP!!!
2 4
*/