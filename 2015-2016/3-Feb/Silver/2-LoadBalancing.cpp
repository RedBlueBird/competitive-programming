#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    ofstream fout("balancing.out");
//    ifstream fin("balancing.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> coordsx(n);
    vector<pair<int,int>> coordsy(n);
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        coordsx[i].first = a;
        coordsx[i].second = b;
        coordsy[i].first = b;
        coordsy[i].second = a;
    }

    //Using the coordinate x,y of the cows to determine the possible fences
    //Determine the most optimal vertical fence by using the x coordinates of the cows
    //Then iterate through the cows y coordinate to find the maximum cows from 4 sectors
    sort(coordsx.begin(),coordsx.end());
    sort(coordsy.begin(),coordsy.end());
    vector<pair<int,int>> sums;
    int a = 0, b = 0, c = 0, d = 0;
    sums.push_back(make_pair(0,0));
    for (int i = 0; i < n; i++){
        if (sums.back().second == coordsx[i].first){
            sums.back().first++;
        }
        else{
            sums.push_back(make_pair(sums.back().first+1, coordsx[i].first));
        }
    }
    int mins = INT_MAX, xdex = 0;
    for (int i = 0; i < sums.size(); i++){
        if (mins > abs(sums[i].first - (sums.back().first - sums[i].first))){
            mins = abs(sums[i].first - (sums.back().first - sums[i].first));
            c = sums[i].first;
            d = sums.back().first - sums[i].first;
            xdex = sums[i].second;
        }
    }
    for (auto i: sums){
        cout << i.first << " " << i.second << " \n";
    }
    cout << xdex << " \n";
    int ans = max(c,d);
    int lever = 0;
    for (int i = 0; i < n; i++){
        lever = coordsy[i].first;
        while (i < n && coordsy[i].first == lever) {
            if (coordsy[i].second <= xdex) {
                c--;
                a++;
            } else {
                d--;
                b++;
            }
            i++;
        }
        i--;
        ans = min(ans,max(max(a,c),max(b,d)));
        cout << a << " " << b << " " << c << " " << d << " \n";
    }

    //Output
    fout << ans;

    return 0;
}