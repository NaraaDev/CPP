#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int nums[n];

    map<int,int> mp;

    int ans = 0;


    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int cur = 0;
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(mp.find(nums[i]) != mp.end()) {
            if(mp[nums[i]] >= start) 
                start = mp[nums[i]] + 1;
            mp[nums[i]] = i;
        } else {
            mp[nums[i]] = i;
        }
        ans = max(ans, i - start + 1);
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!

8
1 2 1 3 2 7 4 2
*/