#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Find the k-th successor in logN time with computed data
int find(vector<vector<int>>& succ, int x, int k){
    for (int i = 0; i < 30; i++)
        if (k & (1<<i))
            x = succ[i][x];
    return x;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, q;
    cin >> n >> q;
    vector<vector<int>> succ(30, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        cin >> succ[0][i];
    }

    //Precompute the 2^k-th successor using binary lifting
    for (int i = 1; i < 30; i++){
        for (int j = 1; j <= n; j++){
            succ[i][j] = succ[i-1][succ[i-1][j]];
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        cout << find(succ,a,b) << "\n";
    }

    return 0;
}