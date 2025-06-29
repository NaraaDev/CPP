#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void uCan() {
    int n, k;
    cin >> n >> k;
    ordered_set<int> childs;
    for(int i = 1; i <= n; i++) {
        childs.insert(i);
    }

    int idx = k;
    
    while(childs.size()) {
        idx %= childs.size();
        int x = *childs.find_by_order(idx);
        childs.erase(x);
        cout << x << ' ';
        idx += k;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;
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