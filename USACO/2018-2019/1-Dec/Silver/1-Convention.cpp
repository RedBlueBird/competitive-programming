#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Binary search using the selected threshold
//Return true if its within restriction, false otherwise
bool bisearch(int bs, vector<int>& cows, int m, int c, int& diff){
    int n = cows.size();
    int start = 0;
    int buses = 1;
    for (int i = 0; i < n; i++){
        if (cows[i] - cows[start] > bs){
            start = i;
            buses++;
        }
        else if (i - start >= c){
            start = i;
            buses++;
        }
        diff = max(cows[i] - cows[start], diff);
    }
    if (buses <= m){
        return true;
    }
    return false;
}

int main() {
    ofstream fout("convention.out");
    ifstream fin("convention.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n,m,c;
    fin >> n >> m >> c;
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }

    //Sort the cows by their arrive time
    //Binary search the most optimal threshold to categorize the cows into different buses
    sort(cows.begin(), cows.end());
    int a = 0;
    int b = 1000000000;
    int diff = 0;
    while (b-a>1){
        diff = 0;
        bool result = bisearch((b+a)/2, cows, m, c, diff);
        if (result){
            b -= (b-a)/2;
        }
        else{
            a += (b-a)/2;
        }
    }
    if (!bisearch(a, cows, m,c,diff)) bisearch(b,cows,m,c,diff);

    //Output
    fout << diff;

    return 0;
}