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

struct Project {
    int start, end;
    ll money;
};

void uCan() {
    map<int ,int > comp;

    int n;
    cin >> n;

    vector<Project> projects(n);

    for(int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].money;
        projects[i].end++;
        comp[projects[i].start];
        comp[projects[i].end];
    }

    int coords = 0;

    for(auto &v: comp) {
        v.second = coords++;
    }

    vector<vector<pair<int, int> > > project(coords);

    for(int i= 0; i < n; i++) {
        project[comp[projects[i].end]].emplace_back(comp[projects[i].start], projects[i].money);
    }

    vector<ll > dp(coords, 0);

    for(int i = 0; i < coords; i++) {
        if(i > 0) {
            dp[i] = dp[i - 1];
        }

        for(auto p: project[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }


    cout << dp[coords - 1];


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