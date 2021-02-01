#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("badmilk.out");
    ifstream fin("badmilk.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Create a vector set that track all the people a milk type is given to
    //A vector vector pair that includes all the milk a person drank at some point in time
    int n,m, d,s;
    fin >> n >> m >> d >> s;
    vector<set<int>> milks(m+1);
    vector<vector<pair<int,int>>> people(n+1);
    for (int i = 0; i < d; i++){
        int a,b,c;
        fin >> a >> b >> c;
        milks[b].insert(a);
        people[a].push_back(make_pair(b,c));
    }

    //If the sick person drank a milk type before they got sick,
    //include that person in that milk type
    vector<set<int>> counts(m+1);
    for (int i = 0; i < s; i++){
        int a,b;
        fin >> a >> b;
        for (int j = 0; j < people[a].size(); j++){
            if (people[a][j].second < b){
                counts[people[a][j].first].insert(a);
            }
        }
    }

    //Output the milk with the highest amount of people getting sick
    for (int i = 1; i <= m; i++){
        if (counts[i].size() == s){
            fout << milks[i].size();
            return 0;
        }
    }

    return 0;
}