#include<bits/stdc++.h>

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
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int x[n];

        for(int i = 0; i < n; i++)
            cin >> x[i];


        cout << "? 1 2" << endl;
        cout.flush();
        int ans;
        cin >> ans;
        cout << "? 1 3" << endl;
        cout.flush();
        int ans1;
        cin >> ans1;

        if(ans == 0 || ans1 == 0) {
            cout << "! A" << endl;
            cout.flush(); 
        } else {
            cout << "! B" << endl;
            cout.flush(); 
        }
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/