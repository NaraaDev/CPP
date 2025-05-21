#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int left = 1, right = 1e9;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        cout << "? " << mid << endl;
        string s;
        cin >> s;
        if(s == "YES") {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "! " << left << endl;

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
*/