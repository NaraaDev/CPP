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

    queue<int> q;

    for(int i = 1; i <= n; i++)
        q.push(i);
    

    while(q.size() != 1) {
        q.push(q.front());
        q.pop();
        cout << q.front() << ' ';
        q.pop();
    }

    cout << q.front();

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/