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

//Check if a point is left/right/collinear with the line
int dir(point p1, point p2, point p3){
    ll det = ((p2.x-p1.x)*(p3.y-p2.y) - (p2.y-p1.y)*(p3.x-p2.x));
    return det == 0 ? 0 : det > 0 ? 1 : -1;
}

//Check if the point is within the line segment
bool within(point p1, point p2, point p3){
    if (dir(p1,p2,p3)==0)
        return (p3.x>=min(p1.x,p2.x)&&p3.x<=max(p1.x,p2.x)&&(p3.y>=min(p1.y,p2.y))&&(p3.y<=max(p1.y,p2.y)));
    return false;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //All there is to know is in the code
    //Two line segment intersects if they cross
    //or they are partially contained within each other
    for (int i = 0; i < n; i++){
        struct point p1,p2,p3,p4;
        cin >>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
        if ((dir(p1,p2,p3)!=dir(p1,p2,p4))&&(dir(p3,p4,p1)!=dir(p3,p4,p2)))
            cout << "YES\n";
        else if (within(p1,p2,p3)||within(p1,p2,p4)||within(p3,p4,p1)||within(p3,p4,p2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}