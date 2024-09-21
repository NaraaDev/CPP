#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back


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

    pair<int, int> nums[n];

    for(int i = 0; i < n; i++) {
        cin >> nums[i].F;
        nums[i].S = i;
    }

    sort(nums, nums + n);

    int ans = 1;
    int pos = nums[0].S;

    for(int i = 0; i < n - 1; i++) {
        if(nums[i + 1].S < nums[i].S) {
            ans++;
        }
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
3
*/