#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> xp(n);
    vector<pair<int,int>> yp(n);
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        xp[i].first = a;
        xp[i].second = b;
        yp[i].first = b;
        yp[i].second = a;
    }

    sort(xp.begin(), xp.end());
    sort(yp.begin(), yp.end());
    map<tuple<int,int,int,int>,int> visited;
    ll total = 0;
    for (int i = 0; i < n; i++){
        int x1 = xp[i].first, y1 = xp[i].second;
        int x2 = x1, y2 = y1;
        for (int j = i+1; j < n; j++){
            x1 = max(x1, xp[j].first);
            y1 = max(y1, xp[j].second);
            x2 = min(x2, xp[j].first);
            y2 = min(y2, xp[j].second);
            if (visited.count(tuple<int,int,int,int>{x1,y1,x2,y2})) continue;
            visited[tuple<int,int,int,int>{x1,y1,x2,y2}]++;
            int counts = 0;
            for (int k = i+1; k < j; k++){
                if (xp[k].second < y1 && xp[k].second > y2) counts++;
            }
            total += pow(2,counts)-1;
        }
    }
    for (int i = 0; i < n; i++){
        int x1 = yp[i].second, y1 = yp[i].first;
        int x2 = x1, y2 = y1;
        int counts = 0;
        for (int j = i+1; j < n; j++){
            x1 = max(x1, yp[j].second);
            y1 = max(y1, yp[j].first);
            x2 = min(x2, yp[j].second);
            y2 = min(y2, yp[j].first);
            if (visited.count(tuple<int,int,int,int>{x1,y1,x2,y2})) continue;
            visited[tuple<int,int,int,int>{x1,y1,x2,y2}]++;
            int counts = 0;
            for (int k = i+1; k < j; k++){
                if (yp[k].second < x1 && yp[k].second > x2) counts++;
            }
            total += pow(2,counts)-1;
        }
    }

    //Output
    fout << pow(2,n) - total;

    return 0;
}