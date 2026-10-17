#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int sz, LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, component;

    Tree(int sz)
        : sz(sz),
          adj(sz + 1),
          depth(sz + 1, -1),
          component(sz + 1)
    {
        LOG = 1;

        while ((1 << LOG) <= max(1, sz))
            LOG++;

        up.assign(LOG, vector<int>(sz + 1));
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build()
    {
        vector<int> st;

        for (int root = 1; root <= sz; root++)
        {
            if (depth[root] != -1)
                continue;

            depth[root] = 0;
            component[root] = root;
            st.push_back(root);

            while (!st.empty())
            {
                int u = st.back();
                st.pop_back();

                for (int v : adj[u])
                {
                    if (depth[v] != -1)
                        continue;

                    depth[v] = depth[u] + 1;
                    component[v] = root;
                    up[0][v] = u;

                    for (int k = 1; k < LOG; k++)
                        up[k][v] = up[k - 1][up[k - 1][v]];

                    st.push_back(v);
                }
            }
        }
    }

    int lca(int u, int v) const
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if (diff & (1 << k))
                u = up[k][u];

        if (u == v)
            return u;

        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[k][u] != up[k][v])
            {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    int distance(int u, int v) const
    {
        if (u == 0 || v == 0 || component[u] != component[v])
            return -1;

        int w = lca(u, v);

        return depth[u] + depth[v] - 2 * depth[w];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    int W = n + 2;

    vector<string> grid(W, string(W, '.'));

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        for (int j = 1; j <= n; j++)
            grid[i][j] = s[j - 1];
    }

    vector<int> H(W * W), V(W * W);

    int hCount = 0;
    int vCount = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] != '#')
                continue;

            if (grid[i][j - 1] != '#')
                hCount++;

            H[i * W + j] = hCount;
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (grid[i][j] != '#')
                continue;

            if (grid[i - 1][j] != '#')
                vCount++;

            V[i * W + j] = vCount;
        }
    }

    Tree horizontal(hCount);
    Tree vertical(vCount);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] != '#')
                continue;

            int p = i * W + j;

            if (grid[i - 1][j] == '#')
            {
                bool duplicate =
                    H[p - 1] == H[p] &&
                    H[p - W - 1] == H[p - W];

                if (!duplicate)
                    horizontal.addEdge(H[p], H[p - W]);
            }

            if (grid[i][j - 1] == '#')
            {
                bool duplicate =
                    V[p - W] == V[p] &&
                    V[p - W - 1] == V[p - 1];

                if (!duplicate)
                    vertical.addEdge(V[p], V[p - 1]);
            }
        }
    }

    horizontal.build();
    vertical.build();

    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int p1 = r1 * W + c1;
        int p2 = r2 * W + c2;

        int d1 = horizontal.distance(H[p1], H[p2]);
        int d2 = vertical.distance(V[p1], V[p2]);

        if (d1 == -1 || d2 == -1)
            cout << -1 << '\n';
        else
            cout << d1 + d2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
Hoorhon nomio Zarimdaa aashtai nomio
*/
