#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
    ofstream fout("248.out");
    ifstream fin("248.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> dp(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
        fin >> dp[i][0];

    //3d dp
    //Compute the highest possible score for each subinterval
    //If the subinterval cannot be merged into 1 single number, then it is marked as incompatible
    //That subinterval will have a score of 0
    //While computing those, save the best outcome as the final answer
    int ans = 0;
    for (int j = 1; j < n; j++){
        for (int i = 0; i + j < n; i++){
            for (int k = 0; k < j; k++){
                if (dp[i][k] == dp[i+k+1][j-k-1] && dp[i][k]){
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    //Output
    fout << ans;

    return 0;
}

