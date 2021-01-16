#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    string dna;
    cin >> dna;
    int n = dna.size();

    //The streak will increase until the current letter and the previous letter become different
    //The maximum streak is the answer
    int maxs = 1;
    int curr = 1;
    for (int i = 1; i < n; i++){
        if (dna[i] == dna[i-1]){
            curr++;
        }
        else{
            curr = 1;
        }
        maxs = max(maxs, curr);
    }

    //Output
    cout << maxs;

    return 0;
}