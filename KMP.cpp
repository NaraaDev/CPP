#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string p)
{
    int n = p.size();

    vector<int> lps(n, 0);

    int j = 0;
    // ababcabab
    // 001201234
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = lps[j - 1];
        }

        if (p[i] == p[j])
        {
            j++;
        }

        lps[i] = j;
    }

    return lps;
}

vector<int> KMP(string s, string p)
{
    vector<int> lps = buildLPS(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = lps[j - 1];

        if (s[i] == p[j])
            j++;

        if (j == m)
        {
            ans.push_back(i - m + 1);
            j = lps[j - 1];
        }
    }
    return ans;
}

int main()
{
    string s, p;
    cin >> s >> p;

    vector<int> ans = KMP(s, p);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
