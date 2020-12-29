#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mod = 1;

//Sort the values highest to lowest after mod
bool cmp(int a, int b){
    return a%mod > b%mod;
}

int main() {
    ofstream fout("berries.out");
    ifstream fin("berries.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> berries(n);
    int top = 0;
    for (int i = 0; i < n; i++) {
        fin >> berries[i];
        top = max(top, berries[i]);
    }

    //Try all the possible Q, where Q is amount of berries each basket can have at max
    //If Q is between k/2 and k, then try values lower than Q for the remaining baskets
    int maxs = 0;
    for (int i = 1; i <= top; i++) {
        int total = 0;
        for (int j = 0; j < n; j++){
            total += berries[j]/i;
        }
        if (total >= k){
            maxs = max(maxs, k/2 * i);
            continue;
        }
        if (total < k/2){
            break;
        }
        mod = i;
        sort(berries.begin(), berries.end(), cmp);
        int sums = (total-k/2)*i;
        for (int j = 0; j < n && j+total < k; j++)
            sums += berries[j]%i;
        maxs = max(maxs, sums);
    }

    //Output
    fout << maxs;

    return 0;
}