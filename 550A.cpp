#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
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
    
    string s, s1;
    cin >> s;
    s1 = s;
    int len = s.length();
    bool isFound = false;
    for(int i = 0; i < len - 1; i++) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            s[i] = '#';
            s[i + 1] = '#';
            isFound = true;
            break;
        }
    }
    if(!isFound)
        cout << "NO";
    else {
        isFound = false;
        len = s.length();
        for(int i = 0; i < len - 1; i++) {
            if(s[i] == 'B' && s[i + 1] == 'A') {
                cout << "YES";
                exit(0);
            }
        }
        len = s1.length();
    isFound = false;
    for(int i = 0; i < len - 1; i++) {
        if(s1[i] == 'B' && s1[i + 1] == 'A') {
            // s1.erase(i, 2);
            s1[i] = '#';
            s1[i + 1] = '#';
            isFound = true;
            break;
        }
    }
    if(!isFound)
        cout << "NO";
    else {
        isFound = false;
        len = s1.length();
        for(int i = 0; i < len - 1; i++) {
            if(s1[i] == 'A' && s1[i + 1] == 'B') {
                cout << "YES";
                exit(0);
            }
        }
        cout << "NO";
        
    }
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/