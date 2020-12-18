#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Binary search to get the index of a number in a sorted list
int bisearch(const int k, vector<int>& list, bool left=false){
    int a = 0, b = list.size()-1;
    while (b-a>1){
        if (list[(b+a)/2] > k){
            b -= (b-a)/2;
        }
        else{
            a += (b-a)/2;
        }
    }
    if (left && list[a] == k){
        a--;
    }
    return a;
}

int main() {
    ofstream fout("haybales.out");
    ifstream fin("haybales.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, q;
    fin >> n >> q;
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }
    cows.push_back(0);
    cows.push_back(1000000001);
    sort(cows.begin(), cows.end());

    //Taking query inputs and output answers along the way
    //The answer is the difference between the indices
    for (int i = 0; i < q; i++) {
        int fr, ba;
        fin >> fr >> ba;
        fout << bisearch(ba,cows) - bisearch(fr,cows,true) << "\n";
    }

    return 0;
}