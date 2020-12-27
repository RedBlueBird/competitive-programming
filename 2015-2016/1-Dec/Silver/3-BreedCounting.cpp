#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("bcount.out");
    ifstream fin("bcount.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int species = 3;
    int n, m;
    fin >> n >> m;
    vector<vector<int>> breeds(species, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++){
        int a;
        fin >> a;
        for (int j = 0; j < species; j++){
            breeds[j][i] = breeds[j][i-1];
        }
        breeds[a-1][i]++;
    }

    //Find the total number of that species in before b-th of that species list
    //and subtract the total number of species before a-th of that species list
    //to obtain the total number of species between the a,b interval
    //Then output
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        for (int j = 0; j < species; j++){
            fout << breeds[j][b] - breeds[j][a-1];
            if (j != species-1) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}