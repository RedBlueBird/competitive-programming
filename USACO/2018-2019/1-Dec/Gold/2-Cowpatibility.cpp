#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//<comment>
//I know this code looks bad
//But at least this code is easy to understand than the official solution
//</comment>

//Find the total amount of pairs that can be formed from a given number
ll choose(ll n){
    return (n-1)*n/2;
}

int main() {
    ofstream fout("cowpatibility.out");
    ifstream fin("cowpatibility.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> types(n, vector<int>(5));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            fin >> types[i][j];
        }
        sort(types[i].begin(), types[i].end());
    }

    //Count the # occurrence for each distinct tuple of 1 to 5 size
    //Using Principle of Inclusion-Exclusion
    //c(array) = sum(choose(x,2)) for x in array
    //t(x) = array of distinct tuples of x size showed up # times
    //Result = c(n) - c(t(1)) + c(t(2)) - c(t(3)) + c(t(4)) - c(t(5))
    map<tuple<int>,int> one;
    map<tuple<int,int>,int> two;
    map<tuple<int,int,int>,int> three;
    map<tuple<int,int,int,int>,int> four;
    map<tuple<int,int,int,int,int>,int> five;
    for (int c = 0; c < n; c++)
        for (int i = 0; i < 5; i++)
            one[make_tuple(types[c][i])]++;
    for (int c = 0; c < n; c++)
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                two[make_tuple(types[c][i],types[c][j])]++;
    for (int c = 0; c < n; c++)
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++)
                    three[make_tuple(types[c][i], types[c][j], types[c][k])]++;
    for (int c = 0; c < n; c++)
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++)
                    for (int l = k + 1; l < 5; l++)
                        four[make_tuple(types[c][i], types[c][j], types[c][k], types[c][l])]++;
    for (int c = 0; c < n; c++)
        five[make_tuple(types[c][0],types[c][1],types[c][2],types[c][3],types[c][4])]++;
    ll ans = 0;
    for (auto i: one)
        ans += choose(i.ss);
    for (auto i: two)
        ans -= choose(i.ss);
    for (auto i: three)
        ans += choose(i.ss);
    for (auto i: four)
        ans -= choose(i.ss);
    for (auto i: five)
        ans += choose(i.ss);

    //Output
    fout << choose(n) - ans;

    return 0;
}

