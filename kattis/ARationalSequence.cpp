#include <iostream>
using namespace std;

struct Fraction {
    int n, d;
};

void experiment() {
    int e;
    cin >> e;

    Fraction frac;
    char slash;
    cin >> frac.n >> slash >> frac.d;

    int path = 0;   
    int path_index = 0;

    while (frac.d != frac.n) {
        if (frac.d > frac.n) {
            frac.d -= frac.n;
        } else {
            frac.n -= frac.d;
            path |= (1 << path_index);
        }
        path_index++;
    }

    int result = 1;
    for (int i = path_index - 1; i >= 0; i--) {
        if (path & (1 << i)) result = (result << 1) + 1;
        else result <<= 1;
    }

    cout << e << " " << result << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n-- > 0) experiment();
    return 0;
}
