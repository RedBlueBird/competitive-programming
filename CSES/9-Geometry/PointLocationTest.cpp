#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

struct point{
    ll x;
    ll y;
};

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //If cross-product is positive, it is left
    //if cross-product is negative, it is right
    //else it is collinear
    for (int i = 0; i < n; i++){
        struct point p1,p2,p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        ll det = ((p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x));
        if (det > 0)
            cout << "LEFT\n";
        else if (det < 0)
            cout << "RIGHT\n";
        else
            cout << "TOUCH\n";
    }

    return 0;
}