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

void uCan() {

    int n,a , b;
    cin >> n >> a >> b;

    int same = n - (a + b);
    if(a + b > n) {
        cout << "NO\n";
        return;
    }

    vector<int> first(n + 1), second(n + 1);

    for(int i = 1; i <= n; i++) {
        first[i] = i;
        second[i] = i;
    }

    if(a == b) {
        int left = same + 1, last = n;
        int gg = a;
        while(gg--) {
            swap(first[left], first[last]);
            left++;
            last--;
        }
        
    } else {
        if(b > a) {
            reverse(second.begin() + 1 + same, second.end());
            reverse(second.begin() + 1 + same, second.begin() + 1 + same + b);
            reverse(second.begin() + 1 + same + b, second.end());
            
        } else {
            reverse(first.begin() + 1 + same, first.end());
            reverse(first.begin() + 1 + same, first.begin() + 1 + same + a);
            reverse(first.begin() + 1 + same + a, first.end());
        }        
    }

    for(int i = 1; i <= n; i++) {
        if(first[i] > second[i]) a--;
        if(second[i] > first[i]) b--;
    }
    
    if(a != 0 || b != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    
    for(int i = 1; i <= n; i++)
        cout << first[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++)
        cout << second[i] << ' ';
    cout << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

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