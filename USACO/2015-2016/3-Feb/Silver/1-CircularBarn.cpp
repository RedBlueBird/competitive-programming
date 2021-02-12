#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Calculate the sum of all squares from 1 to n
int n2(int n){
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    ofstream fout("cbarn.out");
    ifstream fin("cbarn.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Determine which room have the most cows,
    //Rotate the room array such that that room starts at the beginning.
    int n;
    fin >> n;
    vector<int> barns(n);
    int c = 0;
    for (int i = 0; i < n; i++){
        fin >> barns[i];
        c = max(0, c + barns[i] - 1);
    }
    for (int i = 0; i < n; i++){
        if (c == 0){
            rotate(barns.begin(), barns.begin() + i, barns.end());
            break;
        }
        c = max(0, c + barns[i] - 1);
    }

    //Append to the answer the total energy spent on the cows in this room
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += n2(barns[i] + c - 1) - n2(c - 1);
        c = max(0, c + barns[i] - 1);
    }

    //Output
    fout << ans;

    return 0;
}