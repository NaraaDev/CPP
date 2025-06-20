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

    int n;
    cin >> n;

    vector<tuple<int, int, int> > segments(n);


    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments[i] = make_tuple(i, l, r);
    }

    sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
        if(get<1>(a) == get<1>(b)) {
            return get<2>(a) > get<2>(b);
        }
            return get<1>(a) < get<1> (b);
    });

    vector<int> included(n, 0), including(n, 0);

    int minEnd = 2e9;

    for(int i = n - 1; i >= 0; i--) {
        if(get<2>(segments[i]) >= minEnd) {
            including[get<0>(segments[i])] = 1;
        }
        minEnd = min(minEnd, get<2>(segments[i]));
    }
    int maxEnd = 0;
    for(int i = 0; i < n; i++) {
        if(get<2>(segments[i]) <= maxEnd) {
            included[get<0>(segments[i])] = 1;
        }
        maxEnd = max(maxEnd, get<2>(segments[i]));
    }

    for(int i = 0; i < n; i++) {
        cout << including[i] << ' ';
    }
    cout << '\n';

    for(int i = 0; i < n; i++) {
        cout << included[i] << ' ';
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