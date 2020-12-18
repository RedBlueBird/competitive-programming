#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Undo the code
char recurse(string code, ll itr, ll bottom){
    int n = code.size();
    itr = (bottom+itr-1)%bottom;
    if (itr < n) return code[itr];

    ll a = ceil(log((double) (itr+1) / n) / log(2));
    bottom = pow(2, a - 1) * n;
    return recurse(code, itr, bottom < 3 ? 3 : bottom);
}

int main() {
    ofstream fout("cowcode.out");
    ifstream fin("cowcode.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    string code;
    fin >> code;
    ll itr;
    fin >> itr;

    //Calculate how many duplications has already made before the desired index
    //And output
    fout << recurse(code, itr, itr);

    return 0;
}