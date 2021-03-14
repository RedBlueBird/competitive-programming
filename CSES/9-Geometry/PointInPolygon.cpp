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

//Compute the determinant between the two vectors constructed by 4 points
ll det(point p1, point p2, point p3, point p4){
    return ((p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x));
}

//Check if the area of the determinant is positive negative or zero
ll dir(point p1, point p2, point p3){
    ll result = det(p1,p2,p2,p3);
    return result == 0 ? 0 : result > 0 ? 1 : -1;
}

//Check if two line segments intersect
bool intersect(point p1, point p2, point p3, point p4){
    return ((dir(p1,p2,p3)!=dir(p1,p2,p4))&&(dir(p3,p4,p1)!=dir(p3,p4,p2)));
}

//Check if the point is on the line segment
bool within(point p1, point p2, point p3){
    if (dir(p1,p2,p3)==0)
        return ((p3.x>=min(p1.x,p2.x)&&p3.x<=max(p1.x,p2.x))&&(p3.y>=min(p1.y,p2.y)&&p3.y<=max(p1.y,p2.y)));
    return false;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<point> polygon(n);
    for (int i = 0; i < n; i++){
        cin >> polygon[i].x >> polygon[i].y;
    }

    //For every point
    //Cast an ray from the point to infinity, such that the ray will never hit any lattice points
    //Count # line segments made up the polygon intersect the ray
    //If the amount is odd, then the point is inside, otherwise outside
    //If the point is on a line segment, then say it is on the boundary
    for (int i = 0; i < m; i++){
        struct point curr;
        cin >> curr.x >> curr.y;
        struct point ray = {INT_MAX,curr.y+1};
        int walls = 0;
        for (int j = 0; j < n; j++){
            if (intersect(polygon[j%n],polygon[(j+1)%n],curr,ray)) {
                walls++;
            }
            if (within(polygon[j%n],polygon[(j+1)%n],curr)){
                cout << "BOUNDARY\n";
                walls = -1;
                break;
            }
        }
        if (walls != -1){
            if (walls%2)
                cout << "INSIDE\n";
            else
                cout << "OUTSIDE\n";
        }
    }

    return 0;
}