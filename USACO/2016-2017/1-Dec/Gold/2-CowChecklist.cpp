#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("checklist.out");
    ifstream fin("checklist.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<pair<int,int>> htype(n+1);
    vector<pair<int,int>> gtype(m+1);
    for (int i = 1; i <= n; i++)
        fin >> htype[i].first >> htype[i].second;
    for (int i = 1; i <= m; i++)
        fin >> gtype[i].first >> gtype[i].second;

    //Pre-calculate the distance between all Holsteins and Guernseys
    //Pre-calculate the distance between consecutive Holsteins and Guernseys
    //This can be solved with dynamic programming
    //Hdp(i,j) - Minimum distance after i Hs and j Gs and currently on H
    //Gdp(i,j) - Minimum distance after i Hs and j Gs and currently on G
    //The code below demonstrate the relationship of each dp states
    //Answer will be Hdp(n,m)
    vector<ll> hdists(n+1,0);
    vector<ll> gdists(m+1, 0);
    for (int i = 2; i <= n; i++)
        hdists[i] = pow(htype[i].first-htype[i-1].first,2)+pow(htype[i].second-htype[i-1].second,2);
    for (int i = 2; i <= m; i++)
        gdists[i] = pow(gtype[i].first-gtype[i-1].first,2)+pow(gtype[i].second-gtype[i-1].second,2);
    vector<vector<ll>> dists(n+1, vector<ll>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dists[i][j] = pow(htype[i].first-gtype[j].first,2)+pow(htype[i].second-gtype[j].second,2);
    vector<vector<ll>> hdp(n+1, vector<ll>(m+1, INT_MAX));
    vector<vector<ll>> gdp(n+1, vector<ll>(m+1, INT_MAX));
    hdp[1][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 1 && j == 0) continue;
            hdp[i][j] = min(hdp[i][j], hdp[i-1][j]+hdists[i]);
            hdp[i][j] = min(hdp[i][j], gdp[i-1][j]+dists[i][j]);
            if (j == 0) continue;
            gdp[i][j] = min(gdp[i][j], gdp[i][j-1]+gdists[j]);
            gdp[i][j] = min(gdp[i][j], hdp[i][j-1]+dists[i][j]);
        }
    }

    //Output
    fout << hdp[n][m];

    return 0;
}