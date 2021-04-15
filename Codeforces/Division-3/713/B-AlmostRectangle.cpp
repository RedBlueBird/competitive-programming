#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Get the max and min of x/y coords of each asterisk
    //The rectangle will have its sides restricted by those values
    //If the max and low of x or y is the same, then we can set the max or low to a value we perfer
    int t;
    cin >> t;
    for (int test = 0; test < t; test++){
        int n;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        int xmax = 0, xlow = INT_MAX, ymax = 0, ylow = INT_MAX;
        for (int i = 0; i < n; i++){
            string k;
            cin >> k;
            for (int j = 0; j < n; j++){
                grid[i][j] = k[j];
                if (k[j] == '*'){
                    xmax = max(xmax, i);
                    xlow = min(xlow, i);
                    ymax = max(ymax, j);
                    ylow = min(ylow, j);
                }
            }
        }
        if (xmax == xlow){
            if (xmax != n-1)
                xmax = n-1;
            else
                xlow = 0;
        }
        if (ymax == ylow){
            if (ymax != n-1)
                ymax = n-1;
            else
                ylow = 0;
        }
        grid[xmax][ymax] = '*';
        grid[xmax][ylow] = '*';
        grid[xlow][ymax] = '*';
        grid[xlow][ylow] = '*';

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }


    return 0;
}