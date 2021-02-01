#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("speeding.out");
    ifstream fin("speeding.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<int> speed(100);
    int c = 0;
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        for (int j = c; j < c+a; j++){
            speed[j] = b;
        }
        c += a;
    }

    //Compare all the mph over the 100 miles segments
    //Keep the one with the largest difference
    int ans = 0;
    c = 0;
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        for (int j = c; j < c+a; j++){
            ans = max(ans, max(0,b-speed[j]));
        }
        c += a;
    }

    //Output
    fout << ans;

    return 0;
}