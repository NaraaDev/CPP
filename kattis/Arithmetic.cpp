#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;

    vector<string> binary = {
        "000","001","010","011","100","101","110","111"
    };

    deque<char> hexidecimal;
    deque<char> waiting;

    for (int idx = input.size() - 1; idx >= 0; idx--) {
        char c = input[idx];
        int val = c - '0';
        for (int i = 2; i >= 0; i--) {
            waiting.push_front(binary[val][i]);
        }

        while (waiting.size() >= 4) {
            int s = 0;
            for (int i = 0; i < 4; i++) {
                char bit = waiting.back();
                waiting.pop_back();
                if (bit == '1') s |= (1 << i); 
            }
            if (s < 10) hexidecimal.push_front('0' + s);
            else hexidecimal.push_front('A' + (s - 10));
        }
    }

    if (!waiting.empty()) {
        int s = 0;
        int sz = waiting.size();
        for (int i = 0; i < sz; i++) {
            char bit = waiting.back();
            waiting.pop_back();
            if (bit == '1') s |= (1 << i);
        }
        if (s < 10) hexidecimal.push_front('0' + s);
        else hexidecimal.push_front('A' + (s - 10));
    }

    while (hexidecimal.size() > 1 && hexidecimal.front() == '0') hexidecimal.pop_front();

    for (char c : hexidecimal) cout << c;
    cout << '\n';

    return 0;
}
