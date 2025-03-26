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
struct person {
    int l, r, floor;
};
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        ll n,f, ans = 0;
        cin >> n >> f;
        vector<person> persons(n);
        for(int i = 0; i < n; i++) {
            cin >> persons[i].l >> persons[i].r;
            persons[i].floor = i + 1;
            ans += persons[i].r - persons[i].l;
        }

        sort(persons.begin(), persons.end(), [](person a, person b) {
            if(a.l == b.l)
                return a.r < b.r;
            return a.l < b.l;
        });
        vector<int> last, first;
        for(int i = 0; i < n; i++) {
            if(persons[i].r <= f) {
                last.push_back(persons[i].floor);
            } else {
                if(persons[i].l <= f) {
                    f = persons[i].r;
                } else {
                    ans += persons[i].l - f;
                    f = persons[i].r;
                }
                first.push_back(persons[i].floor);
            }
        }
        cout << ans << '\n';

        for(int i = 0; i < first.size(); i++)
            cout << first[i] << ' ';
        for(int i = last.size() - 1; i >= 0; i--)
            cout << last[i] << ' ';
        
        cout << '\n';

    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/