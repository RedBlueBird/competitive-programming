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

//Sort the points by x then by y
bool sortPoints(point& p1, point& p2){
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

//Calculate the determinant of the vectors formed from 4 points
ll det(point p1, point p2, point p3, point p4){
    return ((p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x));
}

//Check if a point is left/right/collinear with the line segment
int dir(point p1, point p2, point p3){
    ll result = det(p1, p2, p2, p3);
    return result == 0? 0 : result > 0? 1 : -1;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    sort(points.begin(), points.end(), sortPoints);

    //Implementing Andrew's sweep-line convex hull
    //Consisted of upper hull and lower hull
    //Every time a new point is reached, if it form a concave triangle with previous two points
    //then the previous point gets removed
    int c = 0;
    vector<point> hull(2*n);
    for (int i = 0; i < n; i++){
        while (c>=2 && dir(hull[c-2],points[i],hull[c-1])==-1) c--;
        hull[c++] = points[i];
    }
    for (int i = n-2, k = c+1; i >= 0; i--){
        while (c>=k && dir(hull[c-2],points[i],hull[c-1])==-1) c--;
        hull[c++] = points[i];
    }
    hull.resize(c-1);

    //Output
    cout << c-1 << "\n";
    for (point i: hull){
        cout << i.x << " " << i.y << "\n";
    }

    return 0;
}