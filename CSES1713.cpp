#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int MAX_N = 1e6 + 10;

vector<int> primes;

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (n % i == 0) {
            n /= i;
            power++;
        }
        count *= (power + 1);
    }
    if (n > 1) count *= 2;
    return count;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        cout << countDivisors(num) <<  '\n';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/