#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("lifeguards.out");
    ifstream fin("lifeguards.in");
//    ofstream fout ("../output.txt");
//    ifstream fin ("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> times(n);
    for (int i = 0; i < n; i++){
        fin >> times[i].first >> times[i].second;
    }

    //Sort the time gaps.
    //Iterate through the time gaps and sum the unique time gaps up while also check for the minimum time gap
    //Return total gap - minimum gap
    times.push_back(make_pair(1000000001,1000000001));
    sort(times.begin(), times.end());
    int mins = INT_MAX;
    int sums = 0;
    int latest = 0;
    for (int i = 0; i < n; i++){
        int cover = 0;
        if (times[i].first > latest){
            cover = times[i].second - times[i].first;
        }
        else if (times[i].second > latest){
            cover = times[i].second - latest;
        }
        else{
            mins = 0;
        }
        sums += cover;
        if (times[i].second < times[i+1].first){
            mins = min(mins, cover);
        }
        else if (times[i+1].second > times[i].second){
            mins = min(mins, cover - (times[i].second - max(times[i+1].first, latest)));
        }
        latest = max(latest, times[i].second);
    }

    //Output
    fout << sums - mins;

    return 0;
}