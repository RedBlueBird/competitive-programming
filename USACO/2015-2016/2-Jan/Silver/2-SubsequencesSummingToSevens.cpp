#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("div7.out");
    ifstream fin("div7.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs by their sum mod 7
    int n;
    fin >> n;
    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++){
        fin >> cows[i];
        cows[i] = (cows[i]+cows[i-1])%7;
    }

    //Find the first and last of the same value in the list
    //The cow ids between them must be divisible by 7
    //The difference between the first and last of these index must be the answer
    int ans = 0;
    vector<int> left(7);
    vector<int> right(7);
    for (int i = 1; i <= n; i++){
        right[cows[i]] = i;
    }
    for (int i = n; i > 0; i--){
        left[cows[i]] = i;
    }
    for (int i = 0; i < 7; i++){
        ans = max(ans, right[i]-left[i]);
    }

    //Output
    fout << ans;

    return 0;
}