#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


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

    vector<pair<int ,int> > movies(n);

    for(int i = 0; i < n; i++) {
        cin >> movies[i].S >> movies[i].F;        
    }

    sort(movies.begin(), movies.end());

    multiset<int> endTime;

    

    for(int i = 0; i < k; i++) {
        endTime.insert(0);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        auto it = endTime.upper_bound(movies[i].S);
        if(it == endTime.begin()) {
            continue;
        } else {
            --it;
            endTime.erase(it);
            endTime.insert(movies[i].F);
            ans++;
        }
    }

    cout << ans;

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