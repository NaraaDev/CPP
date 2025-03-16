#include<bits/stdc++.h>

using namespace std;
//https://codeforces.com/gym/105657/problem/A
const int ALPHA = 26;
int parent[ALPHA], rankk[ALPHA];

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]); 
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
        if (rankk[px] > rankk[py]) parent[py] = px;
        else if (rankk[px] < rankk[py]) parent[px] = py;
        else parent[py] = px, rankk[px]++;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string S1, S2, S3;
        cin >> S1 >> S2 >> S3;
    
        if (S1.size() != S2.size()) {
            cout << "NO\n";
        }
        else if (S1.size() != S3.size()) {
            cout << "YES\n";
        } else {
            iota(parent, parent + ALPHA, 0);
            fill(rankk, rankk + ALPHA, 0);
            int n = S1.size();
            for (int i = 0; i < n; i++) {
               unite(S1[i] - 'a', S2[i] - 'a');
            }
            bool isCan = false;
            for (int i = 0; i < n; i++) {
                if (find(S1[i] - 'a') != find(S3[i] - 'a')) {
                    isCan = true;
                    break;
                }
            }
            cout << (isCan ? "YES\n": "NO\n");
        }
    }
}