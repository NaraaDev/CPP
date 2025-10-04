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

bool isPalindrome(string s) {

    int len = s.length();

    int left = 0, right = len - 1;

    while(left <= right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;

}

void uCan() {

    string s;
    cin >> s;
    
    int len = s.length();
    ll ans = 0;
    if(len == 2) {
        cout << 2;
        return;
    }
    if(isPalindrome(s)) {
        if(len & 1) {
            int mid = len / 2;
            ans = 1;

            int left = mid - 1;
            int right = mid + 1;

            while(left >= 0 && s[mid] == s[left]) {
                ans++;
                left--;
            }

            while(right < len && s[mid] == s[right]) {
                ans++;
                right++;
            }


        } else {
            int start = len / 2 - 1;
            int end = len / 2;

            while(start >= 0 && end < len && s[start] == s[end] && s[start] == s[len / 2] && s[end] == s[len / 2]) {
                ans += 2;
                start--;
                end++;
            }

        }

    } else {

        vector<int> pos;
        int left = 0, right = len - 1;
        while(left <= right) {
            if(s[left] != s[right]) {
                if(left + 1 == right) {
                    pos.pb(left);
                    pos.pb(right);
                } else {
                    if(s[left + 1] == s[right]) {
                        pos.pb(left);
                    } else {
                        pos.pb(right);
                    }
                }
                break;
            }
            left++;
            right--;
        }
        for(int i = 0; i < pos.size(); i++) {
            string ss = "";

            for(int j = 0; j < len; j++) {
                if(j == pos[i]) continue;
                ss += s[j];
            }
            if(isPalindrome(ss)) {
                ans++;
                left = pos[i] - 1;
                right = pos[i] + 1;
                while(left >= 0 && s[left] == s[pos[i]]) {
                    ans++;
                    left--;
                }
                while(right < len && s[right] == s[pos[i]]) {
                    right++;
                    ans++;
                }
            }
        }

        

    }
    cout << ans;

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