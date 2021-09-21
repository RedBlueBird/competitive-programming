#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int Dx[4] = {1,0,-1,0};
int Dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    vector<vector<int>> count(2*n+1, vector<int>(2*n+1));

    vector<int> score = {0,0};
    bool turn = 0;
    for (int i = 0; i < 2*n*n-2*n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a = 2*a-1; b = 2*b-1; c = 2*c-1; d = 2*d-1;
        int x = (a+c)/2, y = (b+d)/2;
        bool complete = false;
        for (int j = 0; j < 4; j++){
            int dx = x + Dx[j], dy = y + Dy[j];
            if (dx < 0 || dx >= count.size() || dy < 0 || dy >= count.size()) continue;
            if ((dx % 2) && (dy % 2)) continue;
            count[dx][dy]++;
            if (count[dx][dy] == 4){
                complete = true;
                score[turn]++;
            }
        }
        if (turn == 0){
            cout << "A";
        }else{
            cout << "B";
        }
        if (!complete){
            turn = !turn;
        }
    }

    //Output
    cout << "\n" << score[0] << " " << score[1];


    return 0;
}