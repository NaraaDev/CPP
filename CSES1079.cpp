#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll fact[N];

void uCan() {

    int a, b;
    cin >> a >> b;

    cout << ((fact[a] % MOD) / (((fact[b] % MOD) * (fact[a - b]) % MOD) % MOD)) << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= N - 1; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] += MOD;
        fact[i] %= MOD;
    }

    while(t--) {
        uCan();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
*/