#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair


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
set<string> st;
void backtrack(string& s, int l, int r) {

    if(l == r) {
        st.insert(s);
        return;
    }
    
    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        backtrack(s, l + 1, r);
        swap(s[l], s[i]);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int size = s.length();

    backtrack(s, 0, size - 1);

    cout << st.size() << '\n';
    set<string> ::iterator it;
    for(it = st.begin(); it != st.end(); it++) 
        cout << *it << '\n';
    

}

/*
RILY <3
NEVER GIVE UP!!!
*/