#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;

    if (k % (a + b) < a) 
        cout << "Barb\n";
    else 
        cout << "Alex\n";

    return 0;
}
