#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("mountains.out");
    ifstream fin("mountains.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> mountains(n);
    for (int i = 0; i < n; i++){
        fin >> mountains[i].first >> mountains[i].second;
    }

    sort(mountains.begin(), mountains.end());
    vector<pair<int,int>> mounts = {{0,0}};
    int x = mountains[0].first;
    int y = 0;
    for (int i = 0; i < n; i++){
        if (mountains[i].first == x && mountains[i].second > y){
            y = mountains[i].second;
            mounts.pop_back();
            mounts.push_back(make_pair(mountains[i].first, mountains[i].second));
        }
        else if ((mountains[i].first - x) <= (y - mountains[i].second)) continue;
        else{
            x = mountains[i].first;
            y = mountains[i].second;
            mounts.push_back(make_pair(mountains[i].first, mountains[i].second));
        }
    }
    mountains = mounts;
    n = mountains.size();
    mounts.clear();
    mounts.push_back(make_pair(0,0));
    x = mountains.back().first;
    y = 0;
    for (int i = n-1; i >= 0; i--){
        if (mountains[i].first == x && mountains[i].second > y){
            y = mountains[i].second;
            mounts.pop_back();
            mounts.push_back(make_pair(mountains[i].first, mountains[i].second));
        }
        else if ((x-mountains[i].first) <= (y - mountains[i].second)) continue;
        else{
            x = mountains[i].first;
            y = mountains[i].second;
            mounts.push_back(make_pair(mountains[i].first, mountains[i].second));
        }
    }

    //Output
    fout << mounts.size();

    return 0;
}