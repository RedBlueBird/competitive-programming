#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 8;

//Recursive backtracking function that find all the possible queen combinations
void search(int y, vector<bool> vert, vector<bool> diag1, vector<bool> diag2, vector<vector<bool>>& taken, ll& ans){
    if (y == N){
        ans++;
        return;
    }
    for (int x = 0; x < N; x++){
        if (vert[x] || diag1[x+y] || diag2[x-y+N-1]) continue;
        if (taken[y][x]) continue;
        vert[x] = diag1[x+y] = diag2[x-y+N-1] = true;
        search(y+1, vert, diag1, diag2, taken, ans);
        vert[x] = diag1[x+y] = diag2[x-y+N-1] = false;
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    vector<vector<bool>> taken(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++){
        string raw;
        cin >> raw;
        for (int j = 0; j < N; j++)
            if (raw[j] == '*')
                taken[i][j] = true;
    }

    //Initiate the backtracking recursion
    ll ans = 0;
    vector<bool> vert(N, false);
    vector<bool> diag1(N*2-1, false);
    vector<bool> diag2(N*2-1, false);
    search(0, vert, diag1, diag2, taken, ans);

    //Output
    cout << ans;

    return 0;
}