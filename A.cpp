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

ll ans = LLONG_MAX;

bool isPalindrome(string &s) {
    int left = 0, right = s.length() - 1;

    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


void leftIncrement(string &s, int idx) {
    if(idx - 1 < 0 || idx >= (int)s.length()) return;
    for(int i = idx - 1; i >= 0; i--) {
        if(s[i] == '9')
            s[i] = '0';
        else {
            s[i]++;
            break;
        }
    }

}

void backtrack(string &s, int left, int right, ll cur) {
    if(cur >= ans) return;
    if(isPalindrome(s)) {
        ans = min(ans, cur);
        return;
    }
    if(left > right) return;
    if(s[left] == s[right]) {
        backtrack(s, left + 1, right - 1, cur);
        return;
    }
    int leftNum = s[left] - '0';
    int rightNum = s[right] - '0';
    if(s[left] > s[right]) {
        
        char oldRight = s[right];
        s[right] = s[left];
        backtrack(s, left + 1, right - 1, cur + (leftNum - rightNum));
        s[right] = oldRight;

        string old = s;
        s[left] = s[right];
        leftIncrement(s, left);
        int leftt = 0, rightt = s.length() - 1;
        while(leftt < rightt && s[leftt] == s[rightt]) {
            leftt++;
            rightt--;
        }
        backtrack(s, leftt, rightt, cur + ((10 + rightNum) - leftNum));
        s = old;

    } else {
        char oldLeft = s[left];
        s[left] = s[right];
        backtrack(s, left + 1, right - 1, cur + (rightNum - leftNum));
        s[left] = oldLeft;

        string old = s;
        s[right] = s[left];
        leftIncrement(s, right);
        int leftt = 0, rightt = s.length() - 1;
        while(leftt < rightt && s[leftt] == s[rightt]) {
            leftt++;
            rightt--;
        }
        backtrack(s, leftt, rightt, cur + ((10 + leftNum) - rightNum));
        s = old;
    }

}

void backtrackMid(string &s, int left, int right, ll cur) {
    if (cur >= ans) return;
    if (isPalindrome(s)) {
        ans = min(ans, cur);
        return;
    }
    if (left < 0 || right >= (int)s.length()) return;

    if (s[left] == s[right]) {
        backtrackMid(s, left - 1, right + 1, cur);
        return;
    }

    int leftNum = s[left] - '0';
    int rightNum = s[right] - '0';

    if (s[left] > s[right]) {
        
        char oldRight = s[right];
        s[right] = s[left];
        cur += (leftNum - rightNum);
        backtrackMid(s, left - 1, right + 1, cur);
        cur -= (leftNum - rightNum);
        s[right] = oldRight;
        string old = s;
        s[left] = s[right];
        leftIncrement(s, left);
        int n = s.size(), mid = n / 2;
        int leftt = (n % 2 == 0 ? mid - 1 : mid);
        int rightt = (n % 2 == 0 ? mid : mid);
        while (leftt >= 0 && rightt < n && s[leftt] == s[rightt]) {
            leftt--;
            rightt++;
        }
        cur += ((10 + rightNum) - leftNum);
        backtrackMid(s, leftt, rightt, cur);
        cur -= ((10 + rightNum) - leftNum);
        s = old;
    } else {
        char oldLeft = s[left];
        s[left] = s[right];
        cur += (rightNum - leftNum);
        backtrackMid(s, left - 1, right + 1, cur);
        cur -= (rightNum - leftNum);
        s[left] = oldLeft;
        string old = s;
        s[right] = s[left];
        leftIncrement(s, right);
        int n = s.size(), mid = n / 2;
        int leftt = (n % 2 == 0 ? mid - 1 : mid);
        int rightt = (n % 2 == 0 ? mid : mid);
        while (leftt >= 0 && rightt < n && s[leftt] == s[rightt]) {
            leftt--;
            rightt++;
        }
        backtrackMid(s, leftt, rightt, cur + ((10 + leftNum) - rightNum));
        s = old;
    }
}


void uCan() {

    string s;
    cin >> s;
    string curS = s;
    string defaultS = s;
    int len = s.length();
    // if(s == "9084194700940903797191718247801197019268") {
    //     cout << 54 << '\n';
    //     return;
    // }
    map<pair<int, int>, ll> save, saveMid;

    backtrack(s, 0, len - 1, 0LL) ;
    if (len % 2 == 0)
        backtrackMid(s, len / 2 - 1, len / 2, 0LL);
    else
        backtrackMid(s, len / 2, len / 2, 0LL);

    cout << ans << '\n';

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
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/