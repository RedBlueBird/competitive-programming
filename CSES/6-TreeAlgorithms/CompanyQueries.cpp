#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the k-th successor of node x
int find(vector<vector<int>>& succ, int x, int k){
    for (int i = 0; i < 30; i++){
        if (k & (1 << i)){
            x = succ[x][i];
        }
    }
    return x;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, q;
    cin >> n >> q;
    vector<vector<int>> succ(n+1, vector<int>(30));
    succ[1][0] = 0;
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        succ[i][0] = a;
    }

    //Precompute all 2^k-th value using binary jumping
    for (int i = 1; i < 30; i++){
        for (int j = 1; j <= n; j++){
            succ[j][i] = succ[succ[j][i-1]][i-1];
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        int node = find(succ, a,b);
        if (node == 0)
            cout << -1 << "\n";
        else
            cout << node << "\n";
    }
    return 0;
}