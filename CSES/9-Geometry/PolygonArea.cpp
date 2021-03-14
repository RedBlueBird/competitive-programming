#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

struct point{
    ll x,y;
};

ll det(point p1, point p2, point p3, point p4){
    return (p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x);
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<point> polygon(n);
    for (int i = 0; i < n; i++){
        cin >> polygon[i].x >> polygon[i].y;
    }

    ll area = 0;
    struct point origin = {0,0};
    for (int i = 0; i < n; i++){
        area += det(origin, polygon[i%n], origin, polygon[(i+1)%n]);
    }

    //Output
    cout << abs(area);

    return 0;
}