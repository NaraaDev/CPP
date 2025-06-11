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

vector<char> words(4);

char ans[502][502];
char a[502][502];


void uCan() {
    words[0] = 'A';
    words[1] = 'B';
    words[2] = 'C';
    words[3] = 'D';
    int n, m;
    cin >> n >> m;
    

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];


    bool isCan = true;
    
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            ans[i][j] = '.';
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int g = 0; g < 4; g++) {
                if(words[g] != ans[i - 1][j] && words[g] != ans[i][j - 1]
                     && words[g] != ans[i + 1][j] && words[g] != ans[i][j + 1] && words[g] != a[i][j]) {
                        ans[i][j] = words[g];
                        break;
                }
            }
        }
    }

    if(!isCan) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
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
*/