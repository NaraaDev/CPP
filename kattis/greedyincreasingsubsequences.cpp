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

int tree[N * 4];
void build(vector<int> &nums, int id, int l, int r) {
    if (l == r) {
        tree[id] = nums[l];
    } else {
        int mid = (l + r) / 2;
        build(nums, id * 2 + 1, l, mid);
        build(nums, id * 2 + 2, mid + 1, r);
        tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
    }
}

void update(int id, int l, int r, int pos) {
    if (l == r) {
        tree[id] = -1;
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(id * 2 + 1, l, mid, pos);
        else
            update(id * 2 + 2, mid + 1, r, pos);
        tree[id] = max(tree[id * 2 + 1], tree[id * 2 + 2]);
    }
}

int query(int id, int tl, int tr, int x) {
    if (tree[id] <= x) return -1;
    if (tl == tr) return tl;

    int mid = (tl + tr) / 2;
    if (tree[id * 2 + 1] > x)
        return query(id * 2 + 1, tl, mid, x);
    else
        return query(id * 2 + 2, mid + 1, tr, x);
}

void uCan() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    build(nums, 0,  0, n - 1);
    int pos = 0;
    vector<vector<int> > ans;
    while(pos < n) {
        vector<int> cur;
        if(nums[pos] == -1) {
            pos++;
            continue;
        }
        int num = nums[pos];
        nums[pos] = -1;
        cur.pb(num);
        update(0, 0, n - 1, pos);
        while(true) {
            int idx = query(0, 0, n - 1, num);
            if(idx == -1) {
                break;
            }
            num = nums[idx];
            nums[idx] = -1;
            update(0, 0, n - 1, idx);
            cur.pb(num);
        }
        pos++;
        if(cur.size() > 0) {
            ans.pb(cur);
        }
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/