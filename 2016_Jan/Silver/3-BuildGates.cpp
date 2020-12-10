#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("gates.out");
    ifstream fin("gates.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs while solving it.
    //As long as a fence revisit an old coordinate with a new path, an enclosed area will be formed
    int n;
    fin >> n;
    string directions;
    fin >> directions;
    int x = 0, y = 0;
    vector<vector<bool>> fences(4001, vector<bool>(4001));
    fences[2000][2000] = true;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (directions[i] == 'N'){
            y += 2;
            if (!fences[2000+y-1][2000+x] && fences[2000+y][2000+x]) ans++;
            fences[2000+y][2000+x] = true;
            fences[2000+y-1][2000+x] = true;
        }
        if (directions[i] == 'S'){
            y -= 2;
            if (!fences[2000+y+1][2000+x] && fences[2000+y][2000+x]) ans++;
            fences[2000+y][2000+x] = true;
            fences[2000+y+1][2000+x] = true;
        }
        if (directions[i] == 'E'){
            x += 2;
            if (!fences[2000+y][2000+x-1] && fences[2000+y][2000+x]) ans++;
            fences[2000+y][2000+x] = true;
            fences[2000+y][2000+x-1] = true;
        }
        if (directions[i] == 'W'){
            x -= 2;
            if (!fences[2000+y][2000+x+1] && fences[2000+y][2000+x]) ans++;
            fences[2000+y][2000+x] = true;
            fences[2000+y][2000+x+1] = true;
        }
    }

    //Output
    fout << ans;

    return 0;
}