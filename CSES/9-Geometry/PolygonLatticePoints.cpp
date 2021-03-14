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
struct point origin = {0,0};

//Determinant of two vectors from 4 points
ll det(point p1, point p2, point p3, point p4){
    return ((p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x));
}

//Greatest common divider of two numbers
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
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

    //Find the area of the polygon
    ll area = 0;
    for (int i = 0; i < n; i++){
        area += det(origin, polygon[i%n], origin, polygon[(i+1)%n]);
    }
    area = abs(area);

    //Find the points on the polygon's boundary with gcd
    //Find the points inside the polygon using Pick's theorem
    //(Inside + Bound/2 - 1 = Area)
    ll bound = 0;
    ll inside = 0;
    for (int i = 0; i < n; i++){
        bound += gcd(abs(polygon[(i+1)%n].x-polygon[i%n].x), abs(polygon[(i+1)%n].y-polygon[i%n].y));
    }
    inside = (area - bound + 2)/2;

    //Output
    cout << inside << " " << bound;

    return 0;
}