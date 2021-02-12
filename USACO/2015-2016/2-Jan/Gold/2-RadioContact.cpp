#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<char,pair<int,int>> moves = {{'N',{0,1}}, {'E',{1,0}}, {'S', {0,-1}}, {'W',{-1,0}}};

int main() {
    ofstream fout("radio.out");
    ifstream fin("radio.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    pair<int,int> farmer;
    pair<int,int> cow;
    string fmoves;
    string cmoves;
    fin >> n >> m >> farmer.first >> farmer.second >> cow.first >> cow.second >> fmoves >> cmoves;

    //Process the input string, convert each step to an integer pair coordinate
    //Compute the energy required between all the coordinates between the farmer and cow
    //dp[i][j] means the minimum energy needed for farmer to walk i steps and cow j steps
    vector<pair<int,int>> fcoords(n+1);
    vector<pair<int,int>> ccoords(m+1);
    fcoords[0] = farmer;
    ccoords[0] = cow;
    int x = farmer.first, y = farmer.second;
    for (int i = 0; i < n; i++){
        x += moves[fmoves[i]].first;
        y += moves[fmoves[i]].second;
        fcoords[i+1] = make_pair(x,y);
    }
    x = cow.first, y = cow.second;
    for (int i = 0; i < m; i++){
        x += moves[cmoves[i]].first;
        y += moves[cmoves[i]].second;
        ccoords[i+1] = make_pair(x,y);
    }
    vector<vector<int>> dists(n+1, vector<int>(m+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dists[i][j] = pow(fcoords[i].first-ccoords[j].first,2)+pow(fcoords[i].second-ccoords[j].second,2);
        }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i != 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j] + dists[i][j]);
            }
            if (j != 0){
                dp[i][j] = min(dp[i][j], dp[i][j-1] + dists[i][j]);
            }
            if (i != 0 && j != 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + dists[i][j]);
            }
        }
    }

    //Output
    fout << dp[n][m];

    return 0;
}