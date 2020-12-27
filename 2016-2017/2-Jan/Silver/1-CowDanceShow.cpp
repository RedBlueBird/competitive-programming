#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Simulate the whole query with the given starter stage set up
//Return a value to help binary search pin down the answer
bool bisearch(vector<int>& cows, priority_queue<int, vector<int>, greater<int>>& stage, int k, int maxs){
    for (int i = stage.size(); i < cows.size(); i++){
        int a = stage.top();
        stage.pop();
        stage.push(a+cows[i]);
        maxs = max(maxs, a+cows[i]);
    }
    if (maxs > k) return false;
    return true;
}

int main() {
    ofstream fout("cowdance.out");
    ifstream fin("cowdance.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }

    //Binary search from range 0 to n-1 for k
    //Repeatedly call the simulation function until k can no longer be decreased
    //and still hit equal or below the time restriction
    int a = 0;
    int b = n-1;
    while ((b-a)>1) {
        priority_queue<int, vector<int>, greater<int>> stage;
        int maxs = 0;
        for (int i = 0; i < (a + b) / 2; i++) {
            stage.push(cows[i]);
            maxs = max(maxs, cows[i]);
        }
        bool result = bisearch(cows, stage, k, maxs);
        if (result){
            b -= (b-a)/2;
        }
        else{
            a += (b-a)/2;
        }
    }
    priority_queue<int, vector<int>, greater<int>> stage;
    int maxs = 0;
    for (int i = 0; i < (a+b)/2; i++) {
        stage.push(cows[i]);
        maxs = max(maxs, cows[i]);
    }
    if (!bisearch(cows, stage, k, maxs)) a = b;

    //Output
    fout << a;

    return 0;
}