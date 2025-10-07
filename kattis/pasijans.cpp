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

int n;
int L[1024];
int A[1024][1024];
int rankTable[1024][1024][10];
int Pos[1024];

void uCan() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> L[i];
        for(int j = 0; j < L[i]; j++) {
            cin >> A[i][j];
        }
    }
    
    for(int bit = 0; (1 << bit) <= 1000; bit++) {
        int len = 1 << bit;
        int half = len / 2;
        
        vector<tuple<ll, int, int>> states; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + len <= L[i]; j++) {
                ll val;
                if(bit == 0) {
                    val = A[i][j];
                } else {
                    val = (ll)rankTable[i][j][bit-1] * 100000100LL + rankTable[i][j+half][bit-1];
                }
                states.pb(make_tuple(val, i, j));
            }
        }
        
        sort(states.begin(), states.end());
        
        ll lastVal = -1;
        int curRank = -1;
        
        for(int k = 0; k < states.size(); k++) {
            if(get<0>(states[k]) != lastVal) {
                lastVal = get<0>(states[k]);
                curRank++;
            }
            rankTable[get<1>(states[k])][get<2>(states[k])][bit] = curRank;
        }
    }
    
    auto cmp = [&](int a, int b) {
        int posA = Pos[a];
        int posB = Pos[b];
        
        for(int bit = 9; bit >= 0; bit--) {
            int len = 1 << bit;
            if(posA + len > L[a] || posB + len > L[b]) continue;
            
            if(rankTable[a][posA][bit] != rankTable[b][posB][bit]) {
                return rankTable[a][posA][bit] < rankTable[b][posB][bit];
            }
            
            posA += len;
            posB += len;
        }
        
        if(L[a] - Pos[a] != L[b] - Pos[b]) {
            return L[a] - Pos[a] > L[b] - Pos[b];
        }
        
        return a < b;
    };
    
    set<int, decltype(cmp)> ms(cmp);
    
    for(int i = 0; i < n; i++) {
        Pos[i] = 0;
        if(L[i] > 0) {
            ms.insert(i);
        }
    }
    
    while(!ms.empty()) {
        int deck = *ms.begin();
        ms.erase(ms.begin());
        
        cout << A[deck][Pos[deck]] << ' ';
        
        Pos[deck]++;
        if(Pos[deck] < L[deck]) {
            ms.insert(deck);
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
People aren't prisoners of fate, they're prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/