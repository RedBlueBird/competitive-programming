#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("feast.out");
    ifstream fin("feast.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, a, b;
    fin >> n >> a >> b;

    //Construct a knapsack to calculate all the values that can be achieved without water
    //Then another knapsack to calculate all the values achieved with water
    vector<int> fruits = {a,b};
    vector<vector<bool>> ks(3, vector<bool>(n+1, false));
    ks[0][0] = true;
    for (int i = 1; i <= fruits.size(); i++){
        for (int j = 0; j <= n; j++){
            if (ks[i-1][j])
                ks[i][j] = true;
            if (j >= fruits[i-1] && ks[i][j-fruits[i-1]]){
                ks[i][j] = true;
            }
        }
    }
    vector<vector<bool>> ks2(3, vector<bool>(n+1, false));
    for (int i = 0; i <= n; i++){
        if (ks[2][i]) {
            ks2[0][i / 2] = true;
        }
    }
    for (int i = 1; i <= fruits.size(); i++){
        for (int j = 0; j <= n; j++){
            if (ks2[i-1][j])
                ks2[i][j] = true;
            if (j >= fruits[i-1] && ks2[i][j-fruits[i-1]]){
                ks2[i][j] = true;
            }
        }
    }

    //Output the highest sum possible
    for (int i = n; i >= 0; i--){
        if (ks2[2][i]){
            fout << i;
            break;
        }
    }

    return 0;
}