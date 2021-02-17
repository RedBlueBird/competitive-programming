#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    ofstream fout("checklist.out");
//    ifstream fin("checklist.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<pair<int,int>> htype(n+1);
    vector<pair<int,int>> gtype(m+1);
    for (int i = 1; i <= n; i++){
        fin >> htype[i].first >> htype[i].second;
    }
    for (int i = 1; i <= m; i++){
        fin >> gtype[i].first >> gtype[i].second;
    }

    vector<vector<int>> dists(n+1, vector<int>(m+1, 0));
    vector<vector<int>> hdists(n+1, vector<int>(n+1, 0));
    vector<vector<int>> gdists(m+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dists[i][j] = pow(htype[i].first-gtype[j].first,2)+pow(htype[i].second-gtype[j].second,2);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            hdists[i][j] = pow(htype[i].first-htype[j].first,2)+pow(htype[i].second-htype[j].second,2);
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            gdists[i][j] = pow(gtype[i].first-gtype[j].first,2)+pow(gtype[i].second-gtype[j].second,2);
        }
    }
    vector<
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << dists[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " - \n";

    //Output

    return 0;
}