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

    vector<pair<int, int> > nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i].F >> nums[i].S;

    sort(nums.begin(), nums.end());

    vector<int> bagtaasan(n, 0), bagtsan(n, 0);

    for(int i = 0; i < n; i++) {
        auto left = lower_bound(nums.begin(), nums.end(), mp(nums[i].F, 0), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        auto right = lower_bound(nums.begin(), nums.end(), mp(0, nums[i].S), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        if(right == nums.end()) {
            cout << i << "sdas\n";
        }
        if(left == nums.begin()) {
            cout << i << "sda\n";
        }

        else if(left != nums.begin() && right != nums.end()) {
            cout << i << ' ' << (left - nums.begin()) << ' ' << (right - nums.begin()) << '\n';
        }
    }


    for(int i = 0; i < n; i++)
        cout << bagtaasan[i] << " \n"[i == n-1];

    for(int i = 0; i < n; i++)
        cout << bagtsan[i] << ' ';

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
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/