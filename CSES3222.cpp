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

    vector<int> nums(n);

    for(auto &p: nums)
        cin >> p;

    map<int, int> ms;

    for(int i = 0; i < k; i++) {
        ms[nums[i]]++;
    }
    cout << ms.size() << ' ';
    for(int i = k; i < n; i++) {
        ms[nums[i - k]]--;
        ms[nums[i]]++;
        if(ms[nums[i - k]] == 0) {
            ms.erase(nums[i - k]);
        }
        cout << ms.size() << ' ';
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
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/