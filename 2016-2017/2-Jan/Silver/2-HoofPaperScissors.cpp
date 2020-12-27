#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("hps.out");
    ifstream fin("hps.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> sums(n+1, vector<int>(3,0));
    for (int i = 1; i <= n; i++) {
        char a;
        int b;
        fin >> a;
        if (a == 'P') b = 2;
        if (a == 'H') b = 0;
        if (a == 'S') b = 1;
        for (int j = 0; j < 3; j++){
            sums[i][j] = sums[i-1][j];
        }
        sums[i][b]++;
    }

    //Find the most possible wins between two intervals for every possible interval pairs
    int ans = 0;
    for (int i = 0; i <= n; i++){
        int a = 0,b = 0;
        for (int j = 0; j < 3; j++){
            a = max(a, sums[i][j]);
            b = max(b, sums[n][j]-sums[i][j]);
        }
        ans = max(ans,a+b);
    }

    //Output
    fout << ans;

    return 0;
}