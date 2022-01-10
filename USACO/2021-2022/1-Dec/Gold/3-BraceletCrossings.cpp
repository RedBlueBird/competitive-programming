#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

struct point{
    int x,y,color;
};

int dir(point p1, point p2, point p3){
    int det = ((p2.x-p1.x)*(p3.y-p2.y) - (p2.y-p1.y)*(p3.x-p2.x));
    return det == 0 ? 0 : det > 0 ? 1 : -1;
}

bool within(point p1, point p2, point p3){
    if (dir(p1,p2,p3)==0)
        return (p3.x>=min(p1.x,p2.x)&&p3.x<=max(p1.x,p2.x)&&(p3.y>=min(p1.y,p2.y))&&(p3.y<=max(p1.y,p2.y)));
    return false;
}

bool intersects(point p1, point p2, point p3, point p4){
    if ((dir(p1,p2,p3)!=dir(p1,p2,p4))&&(dir(p3,p4,p1)!=dir(p3,p4,p2)))
        return true;
    else if (within(p1,p2,p3)||within(p1,p2,p4)||within(p3,p4,p1)||within(p3,p4,p2))
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--){
        //processing inputs
        int n,m;
        cin >> n >> m;
        bool ans = true;
        vector<int> left(n+1, INT_MAX);
        vector<int> right(n+1, 0);
        vector<vector<int>> up(m, vector<int>(n+1, INT_MAX));
        vector<vector<int>> down(m, vector<int>(n+1, 0));
        vector<vector<point>> beacons(m);
        vector<vector<vector<point>>> points(m, vector<vector<point>>(n+1));
        for (int i = 0; i < m; i++){
            int k;
            cin >> k;
            for (int j = 0; j < k; j++){
                struct point p;
                cin >> p.color;
                p.y = j;
                p.x = i;
                beacons[i].push_back(p);
                points[i][p.color].push_back(p);
                left[p.color] = min(left[p.color], i);
                right[p.color] = max(right[p.color], i);
                up[i][p.color] = min(up[i][p.color], j);
                down[i][p.color] = max(down[i][p.color], j);
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 1; j <= n; j++){
                if (up[i][j] == INT_MAX){
                    if (left[j] <= i && right[j] >= i){
                        ans = false;
                        break;
                    }
                    continue;
                };
                for (int k = j+1; k <= n; k++){
                    if (up[i][j] == INT_MAX) continue;
//                    if (intersects(points[i][j][0], points[i][j][1], points[i][k][0], points[i][k][1])){
//                        ans = false;
//                        break;
//                    }
                    if ((up[i][j] > up[i][k] && down[i][j] > down[i][k]) || (up[i][k] > up[i][j] && down[i][k] > down[i][j])){
                        ans = false;
                        cout << j << " " << k << "\n";
                        break;
                    }
                }
            }
            if (!ans) break;
        }

//        for (int i = 1; i < m; i++){
//            if (!ans) break;
//            for (int j = 1; j <= n; j++){
//                if (up[i][j] == INT_MAX || up[i-1][j] == INT_MAX) continue;
//                for (int k = j+1; k <= n; k++){
//                    if (up[i][j] == INT_MAX || up[i-1][j] == INT_MAX) continue;
//                    if (intersects(points[i-1][j][0], points[i][j][0], points[i-1][k][0], points[i][k][0])){
//                        ans = false;
//                        break;
//                    }
//                    if (intersects(points[i-1][j][1], points[i][j][1], points[i-1][k][1], points[i][k][1])){
//                        ans = false;
//                        break;
//                    }
//                }
//            }
//        }

        if (ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}