#include<bits/stdc++.h>


#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b) {

    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve() {

    int n, target;
    cin >> n >> target;

    vector<pair<int, int> > nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end());

    int left = 0, right = n - 1;
    bool found = false;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid].first > target) {
            right = mid - 1;
        } else if(nums[mid].first == target) {
            left = nums[mid].second;
            found = true;
            break;
        } else {
            left = mid + 1;
        }
    }
    // 1 2 3 4 5 -> 1 4 2 3 5
    // cout << (found ? left : -1);
    if(found) {
        cout << left;
    } else {
        cout << -1;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/