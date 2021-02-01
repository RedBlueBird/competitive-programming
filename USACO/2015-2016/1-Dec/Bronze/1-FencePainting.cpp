#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("paint.out");
    ifstream fin("paint.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int a,b,c,d;
    fin >> a >> b >> c >> d;

    //Sort the two intervals
    if (a > c){
        swap(a,c);
        swap(b,d);
    }

    //Three scenarios:
    //a --- b     c --- d
    //a --- c === b --- d
    //a --- c === d --- b
    if (c > b){
        fout << b-a+d-c;
    }else{
        d = max(d,b);
        fout << d-a;
    }

    return 0;
}