#include<bits/stdc++.h>
// Magic Cards
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m, f;
    cin >> n >> k >> m >> f;

    map<string, pair<int, int> > mp;

    vector<vector<bool>> nums(k, vector<bool>(n + 1, false));

    int num;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < m; j++) {
            cin >> num;
            nums[i][num] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        string calc = "";
        for(int j = 0; j < k; j++)
            calc += (nums[j][i] ? "Y": "N");
        if(mp.find(calc) != mp.end()) {
            mp[calc].second = 2;
        } else {
            mp[calc].first = i;
            mp[calc].second = 1;
        }
    }
    while(f--) {
        string s;
        cin >> s;
        if(mp.find(s) == mp.end() || mp[s].second == 2){
            cout << 0 << '\n';
        } else {
            cout << mp[s].first << '\n';
        }
    } 

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/