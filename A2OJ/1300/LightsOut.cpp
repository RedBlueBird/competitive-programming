#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int Dx[] = {0,1,0,-1,0};
int Dy[] = {0,0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    //Iterate through all the positions the current position can affect
    //Increase the positions by the amount of toggles the current light received
    vector<vector<int>> ans(3, vector<int>(3));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int a;
            cin >> a;
            for (int k = 0; k < 5; k++){
                int dx = i+Dx[k], dy = j+Dy[k];
                if (dx < 0 || dx >= 3 || dy < 0 || dy >= 3) continue;
                ans[dx][dy] += a;
            }
        }
    }

    //Output
    //If the amount of toggles the position received is odd, then the light is off
    //otherwise it is on
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (ans[i][j]%2)
                ans[i][j] = 0;
            else
                ans[i][j] = 1;
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}