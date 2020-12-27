#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("highcard.out");
    ifstream fin("highcard.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> opp(n);
    for (int i = 0; i < n; i++){
        fin >> opp[i];
    }

    //Sort the moves
    //Iterate backward until the player have a higher number card than the opponent
    //Then answer plus 1
    sort(opp.begin(), opp.end());
    int c = 1;
    int ans = 0;
    vector<int> self;
    for (int i = 0; i < n; i++){
        while (opp[i] > c){
            self.push_back(c++);
        }
        c = opp[i]+1;
    }
    if (c-1 != 2 * n){
        while (c-1 != 2 * n){
            self.push_back(c++);
        }
    }
    c = n-1;
    for (int i = n-1; i >= 0; i--){
        while (i >= 0 && self[c] <= opp[i]){
            i--;
        }
        if (self[c] > opp[i]) ans++;
        c--;
    }

    //Output
    fout << ans;

    return 0;
}