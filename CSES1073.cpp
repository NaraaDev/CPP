#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
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

    multiset<int> ans;


    for(int  i = 0; i < n; i++) {
        int cub;
        cin >> cub;

        auto it = ans.upper_bound(cub);

        if(it == ans.end()) 
            ans.insert(cub);
        else {
            ans.erase(it);
            ans.insert(cub);
        }
    }

    cout << ans.size();

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/