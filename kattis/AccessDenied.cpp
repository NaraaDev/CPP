#include <bits/stdc++.h>
using namespace std;

int get_time() {
    string result;
    getline(cin, result);
    if (result == "ACCESS GRANTED") return -1;

    size_t start = result.find_last_of('(');
    size_t end = result.find_last_of('m');
    int time = stoi(result.substr(start + 1, end - start - 1));
    return time;
}

pair<int,int> find_size() {
    int size = 1;
    while (true) {
        cout << string(size, 'A') << endl;
        int time = get_time();
        if (time == -1) return {-1,-1};
        if (time > 5) return {size, time};
        size++;
    }
}

void guess(int n, int t) {
    vector<char> pw(n, 'A');
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    unordered_map<int,int> index_of_time;
    for (int i = 0; i < 21; i++) {
        int key = (1+1+3+1+3)*i + 1+3+10;
        index_of_time[key] = i;
    }

    int next_char_idx = 1;
    int t1 = t;

    while (true) {
        int idx = index_of_time[t1];
        pw[idx] = alphabet[next_char_idx];
        cout << string(pw.begin(), pw.end()) << endl;

        int t2 = get_time();
        if (t2 == -1) break;

        if (t2 > t1) next_char_idx = 1;
        else next_char_idx++;
        t1 = t2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int,int> res = find_size();
    if (res.first != -1) guess(res.first, res.second);

    return 0;
}
