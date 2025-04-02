#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
const int BITS = 63;

struct Node {
    long long g;  // bitwise AND of the segment
    long long f;  // mask of bits that have exactly one zero in the segment
} tree[MAXN * 4];

long long a[MAXN];

void build(int u, int l, int r) {
    if (l == r) {
        tree[u].g = a[l];
        tree[u].f = ~a[l];  // bits that are 0 in a[l]
        return;
    }
    int mid = (l + r) / 2;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    tree[u].g = tree[u << 1].g & tree[u << 1 | 1].g;
    tree[u].f = (tree[u << 1].g & tree[u << 1 | 1].f) | (tree[u << 1 | 1].g & tree[u << 1].f);
}

void update_range(int u, int l, int r, int L, int R, long long x) {
    if (r < L || R < l) {
        return;
    }
    if (l == r) {
        a[l] &= x;
        tree[u].g = a[l];
        tree[u].f = ~a[l];
        return;
    }
    int mid = (l + r) / 2;
    update_range(u << 1, l, mid, L, R, x);
    update_range(u << 1 | 1, mid + 1, r, L, R, x);
    tree[u].g = tree[u << 1].g & tree[u << 1 | 1].g;
    tree[u].f = (tree[u << 1].g & tree[u << 1 | 1].f) | (tree[u << 1 | 1].g & tree[u << 1].f);
}

void update_point(int u, int l, int r, int pos, long long x) {
    if (l == r) {
        a[l] = x;
        tree[u].g = x;
        tree[u].f = ~x;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update_point(u << 1, l, mid, pos, x);
    } else {
        update_point(u << 1 | 1, mid + 1, r, pos, x);
    }
    tree[u].g = tree[u << 1].g & tree[u << 1 | 1].g;
    tree[u].f = (tree[u << 1].g & tree[u << 1 | 1].f) | (tree[u << 1 | 1].g & tree[u << 1].f);
}

Node query_segment(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return tree[u];
    }
    int mid = (l + r) / 2;
    if (R <= mid) {
        return query_segment(u << 1, l, mid, L, R);
    } else if (L > mid) {
        return query_segment(u << 1 | 1, mid + 1, r, L, R);
    } else {
        Node left = query_segment(u << 1, l, mid, L, R);
        Node right = query_segment(u << 1 | 1, mid + 1, r, L, R);
        Node res;
        res.g = left.g & right.g;
        res.f = (left.g & right.f) | (right.g & left.f);
        return res;
    }
}

int find_zero_pos(int u, int l, int r, int L, int R, int bit) {
    if (r < L || R < l) {
        return -1;
    }
    if (l == r) {
        return ((a[l] >> bit) & 1) == 0 ? l : -1;
    }
    int mid = (l + r) / 2;
    int left_pos = find_zero_pos(u << 1, l, mid, L, R, bit);
    if (left_pos != -1) {
        return left_pos;
    }
    return find_zero_pos(u << 1 | 1, mid + 1, r, L, R, bit);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            update_range(1, 1, n, l, r, x);
        } else if (op == 2) {
            int s;
            long long x;
            cin >> s >> x;
            update_point(1, 1, n, s, x);
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            Node res = query_segment(1, 1, n, l, r);
            long long best_bit = -1;
            for (int bit = BITS - 1; bit >= 0; --bit) {
                if ((res.f >> bit) & 1) {
                    best_bit = bit;
                    break;
                }
            }
            if (best_bit == -1) {
                cout << res.g << '\n';
            } else {
                int pos = find_zero_pos(1, 1, n, l, r, best_bit);
                long long ans = res.g | (1LL << best_bit);
                cout << ans << '\n';
            }
        }
    }

    return 0;
}