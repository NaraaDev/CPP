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

set<int> s;
vector<int> nums;
int n;
void backtrack() {
    if(nums.size() == n) {
        for(int i: nums)
            cout << i << ' ';
        exit(0);
    }

    for(int i: s) {
        if(nums.empty() || abs(nums.back() - i) > 1) {
            nums.pb(i);
            s.erase(i);
            backtrack();
            s.insert(i);
            nums.pop_back();
        }
    }

}

void uCan() {

    cin >> n;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    if(n <= 3 && n > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    backtrack();

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