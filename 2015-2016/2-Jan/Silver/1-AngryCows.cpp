#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Simulate the ammos consumed for the given cows with given radius
//Return true/false to help adjust the binary search to pin down the minimum possible radius
bool bisearch(vector<int>& cows, int r, int k){
    int ammo = 1;
    int start = 0;
    for (int i = 0; i < cows.size(); i++){
        if (cows[i] - cows[start] > 2 * r){
            ammo++;
            start = i;
        }
    }
    if (ammo > k) return false;
    return true;
}

int main() {
    ofstream fout("angry.out");
    ifstream fin("angry.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    //Pin down the minimum possible radius for k ammos
    //by using the binary search function
    int a = 0;
    int b = 500000000;
    while ((b-a)>1){
        bool result = bisearch(cows, (b+a)/2, k);
        if (result){
            b -= (b-a)/2;
        }
        else{
            a += (b-a)/2;
        }
    }
    if (!bisearch(cows, a, k)) a = b;

    //Output
    fout << a;

    return 0;
}