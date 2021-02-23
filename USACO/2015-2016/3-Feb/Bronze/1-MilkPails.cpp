#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
    ofstream fout("pails.out");
    ifstream fin("pails.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int m;
    vector<int> pails(3);
    fin >> pails[1] >> pails[2] >> m;

    //Knapsack with only 2 objects
    //When finished, answer is the highest available number
    vector<vector<bool>> dp(3,vector<bool>(m+1));
    dp[0][0] = true;
    for (int i = 1; i < 3; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= pails[i] && dp[i][j-pails[i]]){
                dp[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = m; i >= 0; i--){
        if (dp[2][i]) {
            ans = i;
            break;
        }
    }

    //Output
    fout << ans;

    return 0;
}

