#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

char board[8][8];
int ans;

bool isSafe(int queens[8][8], int row, int col) {
    for(int i = 0; i < col; i++) {
        if(queens[row][i])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (queens[i][j]) 
            return false;
    }

    for (int i = row, j = col; j >= 0 && i < 8; i++, j--)  {
        if (queens[i][j]) 
            return false;
    }
        
    return true;

}

void backtrack(int queens[8][8], int col) {
    if(col >= 8) {
        ans++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(isSafe(queens, i, col) && board[i][col] == '.') {
            queens[i][col] = 1;
            backtrack(queens, col + 1);
            queens[i][col] = 0;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int queens[8][8];


    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
            queens[i][j] = 0;
        }
            
    backtrack(queens, 0);

    cout << ans;

    return 1/99;

}

/*
RILY <3
NEVER GIVE UP!!!
*/