#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 3;

int main() {
//    ofstream fout("hps.out");
//    ifstream fin("hps.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<vector<int>> moves(n+1, vector<int>(N));
    map<char,int> convert = {{'H',0}, {'P',1}, {'S',2}};
    for (int i = 1; i <= n; i++){
        char a;
        fin >> a;
        for (int j = 0; j < N; j++){
            moves[i][j] += moves[i-1][j];
        }
        moves[i][convert[a]]++;
    }

    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
    int startmax = 0;
    int startind = 0;
    for (int i = 0; i < N; i++){
        if (startmax < moves[n][i]){
            startmax = moves[n][i];
            startind = i;
        }
    }
    for (int i = 1; i <= n; i++){
        dp[0][i] = moves[i][startind];
    }
    for (int i = 0; i < k; i++){
        int best = 0;
        for (int j = 1; j <= n; j++){
            dp[i+1][j] = dp[i+1][j-1];
//            for (int best = 0; best < i; best++) {
                for (int h = 0; h < N; h++) {
                    dp[i + 1][j] = max(dp[i + 1][j], moves[j][h] - moves[best][h] + dp[i][best]);
                }
//            }
            if (dp[i][j] > dp[i][best]){
                best = j;
            }
        }
    }
//    for (vector<int> i: dp){
//        for (int j: i){
//            cout << j << " ";
//        }
//        cout << "\n";
//    }

    //Output
    fout << dp[k][n];

    return 0;
}