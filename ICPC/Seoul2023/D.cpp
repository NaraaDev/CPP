#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;



void gg() {
  cout << -1 << '\n';
  exit(0);
}

pii solve(int &n) {
  if (n == 0)
    return pii{0, 1};

  char c;
  cin >> c; n--;

  if (isdigit(c)) {
    return pii{c - '0', 1};
  }

  if (c != '(') gg();

  auto [a1, b1]= solve(n);
  auto [a2, b2]= solve(n);
  auto [a3, b3]= solve(n);
  auto ans = pii{a1*a3*b2 + a2*b3*b1, b1*a3*b2};

  if (n == 0) gg();
  cin >> c; n--;
  if (c != ')') gg();

  return ans;
}
int main() {
  cin.tie(0);

  int n; cin >> n;
  auto [a, b] = solve(n);

  if (n != 0) gg();
  auto g = __gcd(a, b);
  cout << a / g << ' ' << b / g << '\n';
}