#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the k-th successor node of x in logN time using precomputed data
int find(vector<vector<int>>& succ, int x, int k){
    for (int i = 0; i < 30; i++){
        if (k & (1<<i)){
            x = succ[i][x];
        }
    }
    return x;
}

int main() {
    ofstream fout("swap.out");
    ifstream fin("swap.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m, k;
    fin >> n >> m >> k;
    vector<pii> moves(m);
    for (int i = 0; i < m; i++){
        fin >> moves[i].ff >> moves[i].ss;
    }

    //Construct successor matrix using binary lifting
    //First column of the matrix is the compressed position after m moves
    //Then precompute the rest with binary lifting dynamically
    vector<vector<int>> succ(30, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        int pos = i;
        for (int j = 0; j < m; j++){
            if (moves[j].ff <= pos && pos <= moves[j].ss){
                pos = moves[j].ff + (moves[j].ss - pos);
            }
        }
        succ[0][pos] = i;
    }
    for (int i = 1; i < 30; i++){
        for (int j = 1; j <= n; j++){
            succ[i][j] = succ[i-1][succ[i-1][j]];
        }
    }

    //Output
    for (int i = 1; i <= n; i++){
        fout << find(succ, i, k) << "\n";
    }

    return 0;
}