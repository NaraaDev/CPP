#include<bits/stdc++.h>

// SCC -> Strongly Connected Component (Хүчтэй холбогдсон бүрэлдэхүүн)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;

vector<bool> visited;

// Эхний DFS: графын бүх оройгоор явж, гарах цагийн дарааллаар (postorder) хадгална
void dfs1(int v, vector<vector<int>> const &adj, vector<int> &order) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, order);
        }
    }
    order.pb(v);
}

// Хоёр дахь DFS: урвуу граф дээр явж нэг хүчтэй холбогдсон бүрэлдэхүүнийг гаргаж авна
void dfs2(int v, vector<vector<int>> const &adj_rev, vector<int> &component) {
    visited[v] = true;
    component.pb(v);

    for (int u : adj_rev[v])
        if (!visited[u])
            dfs2(u, adj_rev, component);
}

void uCan() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n), adj_rev(n);

    int a, b;
    for (int i = 0; i < m; i++) {   // m ирмэгийг унших ёстой
        cin >> a >> b;
        a--, b--;                  // 0-based болгох
        adj[a].pb(b);
        adj_rev[b].pb(a);          // урвуу граф
    }

    // Эхний DFS (гарах цагийн дараалал авах)
    visited.assign(n, false);
    vector<int> order;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i, adj, order);

    // Хоёр дахь DFS (SCC олно)
    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> ans(n, 0);
    int k = 0; // хаант улсын (SCC-ийн) тоо

    for (int v : order) {
        if (!visited[v]) {
            vector<int> component;
            dfs2(v, adj_rev, component);
            k++;
            for (int u : component)
                ans[u] = k; // тухайн орой аль SCC-д харьяалагдаж байгааг хадгална
        }
    }

    // Гаралт
    cout << k << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;  // олон тестэй бол уншина
    t = 1;       // одоо нэг тест
    while (t--) {
        uCan();
    }

    return 0;
}

/*
SCC бодлого (хаант улс):
- Kosaraju алгоритм ашиглаж 2 DFS-ээр хүчтэй холбогдсон бүрэлдэхүүнүүдийг олдог.
- Эхний DFS: гарах цагийн дараалал олно.
- Графыг урвуулаад хоёр дахь DFS: SCC бүрийг гаргаж авна.
- Үр дүнд нь хаант улсын тоо болон гариг бүр аль хаант улсанд багтаж байгааг хэвлэнэ.
*/
