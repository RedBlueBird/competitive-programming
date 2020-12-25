#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("moobuzz.out");
    ifstream fin("moobuzz.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    n--;

    //Since the same cycle repeat every lcm(3,5)
    vector<int> base = {1,2,4,7,8,11,13,14};

    //Output
    fout << n/8 * 15 + base[n%8];

    return 0;
}