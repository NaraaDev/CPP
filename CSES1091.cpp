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
    int n,m;
    cin >> n >> m;

    multiset<int> tickets;

    for(int i = 0; i < n; i++) {
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    

    while(m--) {
        int userPrice;
        cin >> userPrice;

        auto it = tickets.upper_bound(userPrice);
        
        if(it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            cout << (*--it) << '\n';
            tickets.erase(it);
        }
        
    }

    return 1/99;

}

/*
RILY <3
NEVER GIVE UP!!!
3
8
-1
*/