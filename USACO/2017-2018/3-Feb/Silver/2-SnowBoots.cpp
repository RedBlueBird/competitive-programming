#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("snowboots.out");
    ifstream fin("snowboots.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m, a,b;
    fin >> n >> m;
    vector<int> path(n);
    vector<pair<int,int>> boots(m);
    for (int i = 0; i < n; i++){
        fin >> path[i];
    }
    for (int i = 0; i < m; i++){
        fin >> boots[i].first >> boots[i].second;
    }

    //Bruteforce the whole snow path
    //Code self-explanatory
    vector<int> dp(n, m);
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            for (int k = dp[j]; k < m; k++) {
                if (boots[k].second >= i - j && boots[k].first >= path[i] && boots[k].first >= path[j]) {
                    dp[i] = min(dp[i], k);
                    break;
                }
            }
        }
    }

    //Output
    fout << dp[n-1];

    return 0;
}