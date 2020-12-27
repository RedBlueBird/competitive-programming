#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("maxcross.out");
    ifstream fin("maxcross.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k, m;
    fin >> n >> k >> m;
    vector<int> sums(n+1);
    vector<int> broke(m);
    for (int i = 0; i < m; i++){
        fin >> broke[i];
    }

    //Iterate through every signals
    //Find the max signals in a chunk
    //The answer is k - result
    sort(broke.begin(), broke.end());
    int c = 0;
    int maxs = 0;
    for (int i = 1; i <= n; i++){
        sums[i] = sums[i-1] + 1;
        if (i == broke[c]){
            c++;
            sums[i]--;
        }
        if (i >= k){
            maxs = max(maxs, sums[i]-sums[i-k]);
        }
    }

    //Output
    fout << k-maxs;

    return 0;
}