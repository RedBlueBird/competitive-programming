#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("convention2.out");
    ifstream fin("convention2.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> cows(n, vector<int>(3,0));
    for (int i = 0; i < n; i++){
        fin >> cows[i][0] >> cows[i][1];
        cows[i][2] = n-i;
    }
    sort(cows.begin(), cows.end());

    int time = 0;
    int ans = 0;
    priority_queue<vector<int>> queues;
    for (int i = 0; i < n; i++){
        while (!queues.empty() && cows[i][0] > time){
            vector<int> front = queues.top();
            ans = max(ans, time-front[1]);
            time += front[2];
            queues.pop();
        }
        if (cows[i][0] <= time){
            queues.push(vector<int>{cows[i][2], cows[i][0], cows[i][1]});
        }
        else{
            time = cows[i][0] + cows[i][1];
        }
    }
    while (!queues.empty()){
        vector<int> front = queues.top();
        ans = max(ans, time-front[1]);
        time += front[2];
        queues.pop();
    }

    //Output
    fout << ans;

    return 0;
}