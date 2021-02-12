#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    ofstream fout("moocast.out");
//    ifstream fin("moocast.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i].first >> cows[i].second;
    }

    vector<vector<int>> dists(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dists[i][j] = pow(cows[i].first-cows[j].first, 2) + pow(cows[i].second-cows[j].second, 2);
        }
    }


    return 0;
}