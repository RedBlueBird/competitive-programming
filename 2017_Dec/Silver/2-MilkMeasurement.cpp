#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("measurement.out");
    ifstream fin  ("measurement.in");
//    ofstream fout ("../output.txt");
//    ifstream fin ("../input.txt");

    //Take inputs, remap cow ids into 0,1,2...
    int n, k;
    fin >> n >> k;
    map<int,int> remap;
    vector<tuple<int,int,int>> log(n);
    int count = 0;
    for (int i = 0; i < n; i++){
        int a,b,c;
        fin >> a >> b >> c;
        if (!remap.count(b)){
            remap[b] = count++;
        }
        b = remap[b];
        log[i] = tuple<int,int,int>{a,b,c};
    }

    //Track the amount of cows with the highest gallon
    //If the most productive cow decreased on the nth log, the highest gallon will be recounted
    //If each of the following 3 scenarios occurs, the ans will change.
    sort(log.begin(),log.end());
    vector<int> cows(count+1, k);
    int highest = k;
    int ans = 0;
    int track = count+1;

    for (int i = 0; i < n; i++){
        int num = cows[get<1>(log[i])];
        int curr = num + get<2>(log[i]);
        cows[get<1>(log[i])] = curr;

        if (curr < highest && num == highest){
            track--;
            ans++;
            if (track == 0){
                highest = 0;
                for (int j: cows){
                    if (highest == j) track++;
                    if (j > highest){
                        track = 1;
                        highest = j;
                    }
                }
                if (highest == curr && track == 1) ans--;
            }
        }
        else if (curr == highest && num < highest){
            track++;
            ans++;
        }
        else if (curr > highest && !(num == highest && track == 1)){
            track = 1;
            ans++;
        }

        highest = max(highest, curr);
    }

    //Output
    fout << ans;

    return 0;
}