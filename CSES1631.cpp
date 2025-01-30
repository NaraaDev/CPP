#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    ll books[n];

    for(int i = 0; i < n; i++)
        cin >> books[i];
    
    sort(books, books + n);

    
    ll largest = books[n - 1];
    ll smaller = accumulate(books, books + n - 1, 0LL);

    if(largest <= smaller) {
        cout <<  largest + smaller;
    } else {
        cout << largest * 2;
    }
    
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/