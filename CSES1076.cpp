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

multiset<int> low, high;

void balance() {
    while(low.size() > high.size() + 1) {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
    while(low.size() < high.size()) {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}

void insert(int x) {
    if(low.empty() || x <= *prev(low.end()))
        low.insert(x);
    else
        high.insert(x);
    balance();
}

void erase(int x) {
    if(low.find(x) != low.end()) 
        low.erase(low.find(x));
    else
        high.erase(high.find(x));

    balance();
}

int get_median() {
    return *prev(low.end());
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < k; ++i) {
        insert(a[i]);
    }
    cout << get_median();

    for (int i = k; i < n; ++i) {
        erase(a[i - k]);
        insert(a[i]);
        cout << " " << get_median();
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/