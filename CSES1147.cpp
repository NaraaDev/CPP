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

    int n, m;
    cin >> n >> m;

    vector<vector<char > > nums(n, vector<char> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> nums[i][j];
    }

    vector<int> height(m, 0);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] == '.')
                height[j]++;
            else
                height[j] = 0;
        }

        stack<int> st;

        for(int j = 0; j <= m; j++) {

            int curH = (j == m ? 0 : height[j]);

            while(!st.empty() && curH < height[st.top()]) {
                int h = height[st.top()];
                st.pop();

                int left = (st.empty() ? -1 : st.top());
                int width = j - left - 1;

                ans = max(ans, h * width);

            }
            st.push(j);

        }

    }

    cout << ans;

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
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/