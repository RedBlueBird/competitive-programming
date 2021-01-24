#include <bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int main() {
    ofstream fout("art.out");
    ifstream fin("art.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Keep track all the different color's two bounding corners
    //Count all the existing colors, if its 1, return n*n-1
    int n;
    fin >> n;
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    vector<pair<pii,pii>> bound(n*n+1, pair<pii,pii>(pii(INT_MAX, INT_MAX),pii(INT_MIN,INT_MIN)));
    vector<bool> visited(n*n+1, false);
    visited[0] = true;
    int count = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            fin >> grid[i][j];
            bound[grid[i][j]].ff.ff = min(bound[grid[i][j]].ff.ff, i);
            bound[grid[i][j]].ff.ss = min(bound[grid[i][j]].ff.ss, j);
            bound[grid[i][j]].ss.ff = max(bound[grid[i][j]].ss.ff, i);
            bound[grid[i][j]].ss.ss = max(bound[grid[i][j]].ss.ss, j);
            if (!visited[grid[i][j]]){
                visited[grid[i][j]] = true;
                count++;
            }
        }
    }
    if (count == 1){
        fout << n*n-1;
        return 0;
    }

    //Use the bounding corners to create a difference matrix
    //Reconstruct the 2d grid from the different matrix
    //For all the grids with value >1, the color in that coordinate will be eliminated from the possible answers
    vector<vector<int>> presum(n+2, vector<int>(n+2));
    vector<bool> track(n*n+1, false);
    int ans = n*n;
    for (int i = 1; i <= n*n; i++){
        if(bound[i].ff.ff == INT_MAX) continue;
        presum[bound[i].ff.ff][bound[i].ff.ss]++;
        presum[bound[i].ff.ff][bound[i].ss.ss+1]--;
        presum[bound[i].ss.ff+1][bound[i].ff.ss]--;
        presum[bound[i].ss.ff+1][bound[i].ss.ss+1]++;
    }
    for (int i = 1; i < n+2; i++){
        for (int j = 1; j < n+2; j++){
            presum[i][j] += presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (presum[i][j]>1 && !track[grid[i][j]]){
                track[grid[i][j]] = true;
                ans--;
            }
        }
    }

    //Output
    fout << ans;

    return 0;
}