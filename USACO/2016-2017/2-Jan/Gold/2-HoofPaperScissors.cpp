#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("hps.out");
    ifstream fin("hps.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> moves(n+1);
    for (int i = 1; i <= n; i++){
        char a;
        fin >> a;
        if (a == 'P'){
            moves[i] = 0;
        }else if (a == 'H'){
            moves[i] = 1;
        }else{
            moves[i] = 2;
        }
    }

    //Dynamic programming through all the possible n*k*3 combinations
    //The code will be self-explanatory
    //Answer will be the max of all the results
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3)));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (int h = 0; h < 3; h++){
                if (j == 0){
                    dp[i][j][h] += dp[i-1][j][h];
                    if (moves[i] == h)
                        dp[i][j][h]++;
                }else{
                    int state1 = (h+1)%3;
                    int state2 = (h+2)%3;
                    dp[i][j][h] += max(max(dp[i-1][j][h], dp[i-1][j-1][state1]), dp[i-1][j-1][state2]);
                    if (moves[i] == h)
                        dp[i][j][h]++;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++){
        ans = max(ans, dp[n][k][i]);
    }

    //Output
    fout << ans;

    return 0;
}