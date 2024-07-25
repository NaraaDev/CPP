#include<bits/stdc++.h>


using namespace std;

#define ll long long
#define f first
#define s second

int main() {
    
    ll n;
    cin >> n;
    
    while(n != 1) {
        cout << n << ' ';
        if(n & 1) {
            n *= 3;
            n++;
            continue;
        }
        n /= 2;
    }

    cout << n;

}
/*
RILY <3
NEVER GIVE UP!!!
*/