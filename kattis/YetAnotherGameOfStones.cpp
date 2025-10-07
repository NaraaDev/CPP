#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

const ll MOD = 1e9 + 7;

void uCan() {

    int n;
    cin >> n;

    vector<ll> nums(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    if(n == 1) {
        if(b[0] == 0 || (b[0] == 1 && (nums[0] & 1)) || (b[0] == 2 && nums[0] % 2 == 0)) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == 2 && (nums[i] & 1)) {
            cout << "Bob\n";
            return;
        }
    }

    int cnt_b2 = 0, cnt_b1_gt1 = 0;
    for(int i = 0; i < n; i++) {
        if(b[i] == 2) cnt_b2++;
        if(b[i] == 1 && nums[i] > 1) cnt_b1_gt1++;
    }

    if(cnt_b2 + cnt_b1_gt1 > 1) {
        cout << "Bob\n";
        return;
    }

    if(cnt_b1_gt1 == 1) {
        ll x = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] == 1 && nums[i] > 1) {
                x ^= ((nums[i] & 1) ? 0LL : 1LL);
            } else {
                x ^= nums[i];
            }
        }
        cout << (x == 0 ? "Alice\n" : "Bob\n");
        return;
    }

    if(cnt_b2 == 1) {
        ll x = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] != 2) x ^= nums[i];
        }
        cout << (x == 0 ? "Alice\n" : "Bob\n");
        return;
    }

    ll x = 0;
    for(int i = 0; i < n; i++) x ^= nums[i];
    cout << (x != 0 ? "Alice\n" : "Bob\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) uCan();

    return 0;
}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/
