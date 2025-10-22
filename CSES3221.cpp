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

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	deque<int> d;
	vector<int> ret;
	for (int i = 0; i < k; i++) {
		while (!d.empty() && nums[i] < nums[d.back()]) { d.pop_back(); }
		d.push_back(i);
	}
	for (int i = k; i < nums.size(); i++) {
		ret.push_back(nums[d.front()]);
		if (!d.empty() && d.front() <= i - k) { d.pop_front(); }
		while (!d.empty() && nums[i] <= nums[d.back()]) { d.pop_back(); }
		d.push_back(i);
	}
	ret.push_back(nums[d.front()]);
	return ret;
}

void uCan() {

    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;


    vector<int> nums(n);

    nums[0] = x;

    for(int i = 1; i < n; i++)
        nums[i] = (nums[i - 1] * a + b) % c;

    vector<int> ans = maxSlidingWindow(nums, k);
    int gg = 0;
    for(auto it: ans) {
        gg ^= it;
    }
    cout << gg;


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