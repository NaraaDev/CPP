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

 struct CustomCompare {
        bool operator()(const pair<int, int> & a, const pair<int, int> & b) const {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

void uCan() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    multiset<pair<int, int>, CustomCompare> ms;
    map<int, int> cnt;

    for(int i = 0; i < k; i++) {
        cnt[nums[i]]++;
    }

    for(auto it: cnt) {
        ms.insert(mp(it.second, it.first));
    }
    cout << prev(ms.end())->second << ' ';
    for(int i = k; i < n; i++) {
        int out = nums[i - k];
        int in = nums[i];

        ms.erase(ms.find({cnt[out], out}));
        cnt[out]--;
        if(cnt[out] == 0) {
            cnt.erase(out);
        }
        else 
            ms.insert({cnt[out], out});
        
        if(cnt.find(in) != cnt.end()) {
            ms.erase(ms.find({cnt[in], in}));
        }
        cnt[in]++;
        ms.insert({cnt[in], in});

        cout << prev(ms.end())->second << ' ';
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