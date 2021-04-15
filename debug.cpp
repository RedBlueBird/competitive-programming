#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

void debug(vector<vector<int>>& segtree){
    int len = segtree.size()/2;
    for (int i = 1; i < 2*len; i++){
        if (i == len) {
            for (int j = 1; j < 2*len; j++) {
                if (j == len)
                    cout << "| ";
                cout << "- ";
            }
            cout << "\n";
        }
        for (int j = 1; j < 2*len; j++){
            if (j == len)
                cout << "| ";
            cout << segtree[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < 4*len; i++){
        cout << "-";
    }
    cout << "\n";
}

//Update the 1d segment tree
void update(vector<int>& segtree, int x){
    for (x /= 2; x >= 1; x /= 2){
        segtree[x] = max(segtree[2*x], segtree[2*x+1]);
    }
}

//Update the (x,y)th element in 2d segment tree to k
void update2d(vector<vector<int>>& segtree, int x, int y, int k){
    int xlen = segtree.size()/2;
    int ylen = segtree[0].size()/2;
    x += xlen; y += ylen;
    segtree[x][y] = max(segtree[x][y], k);
    for (; x >= 1; x /= 2){
        if (x < xlen)
            segtree[x][y] = max(segtree[2*x][y],segtree[2*x+1][y]);
        update(segtree[x], y);
    }
}

//Get the max element between x1 and x2 in 1d segment tree
int max(vector<int>& segtree, int x1, int x2){
    int maximum = 0;
    while (x1 <= x2){
        if (x1%2)
            maximum = max(maximum, segtree[x1++]);
        if (!(x2%2))
            maximum = max(maximum, segtree[x2--]);
        x1 /= 2;
        x2 /= 2;
    }
    return maximum;
}

//Get the max element between (x1,y2) and (x2,y2) rectangle in 2d segment tree
int max2d(vector<vector<int>>& segtree, int x1, int y1, int x2, int y2){
    int xlen = segtree.size()/2;
    int ylen = segtree[0].size()/2;
    x1 += xlen; x2 += xlen; y1 += ylen; y2 += ylen;
    int maximum = 0;
    while (x1 <= x2){
        if (x1%2)
            maximum = max(maximum, max(segtree[x1++], y1, y2));
        if (!(x2%2))
            maximum = max(maximum, max(segtree[x2--], y1, y2));
        x1 /= 2;
        x2 /= 2;
    }
    return maximum;
}

int main() {
//    ifstream fin("boards.in");
//    ofstream fout("boards.out");
    ifstream fin("../input.txt");
    ofstream fout("../output.txt");

    //Take inputs
    int n, p;
    fin >> n >> p;
    vector<int> xcompress = {0,n}, ycompress = {0,n};
    map<int,int> xconvert, yconvert;
    vector<pair<pii,pii>> ranges(p);
    int x = 0, y = 0;
    for (int i = 0; i < p; i++){
        fin >> ranges[i].ss.ff >> ranges[i].ss.ss >> ranges[i].ff.ff >> ranges[i].ff.ss;
        xcompress.push_back(ranges[i].ff.ff);
        xcompress.push_back(ranges[i].ss.ff);
        ycompress.push_back(ranges[i].ff.ss);
        ycompress.push_back(ranges[i].ss.ss);
    }
    sort(ranges.begin(), ranges.end());
    sort(xcompress.begin(), xcompress.end());
    sort(ycompress.begin(), ycompress.end());
    for (int i = 0; i < 2*p+2; i++){
        if (!xconvert.count(xcompress[i]))
            xconvert[xcompress[i]] = x++;
        if (!yconvert.count(ycompress[i]))
            yconvert[ycompress[i]] = y++;
    }

    int xlen = 0, ylen = 0;
    while ((1<<xlen) <= x) xlen++;
    xlen = 1 << xlen;
    while ((1<<ylen) <= y) ylen++;
    ylen = 1 << ylen;
    vector<vector<int>> segtree(2*xlen, vector<int>(2*ylen));
    for (int i = 0; i < p; i++){
        int dist = (ranges[i].ff.ff-ranges[i].ss.ff)+(ranges[i].ff.ss-ranges[i].ss.ss);
        update2d(segtree, xconvert[ranges[i].ff.ff], yconvert[ranges[i].ff.ss], max2d(segtree, 0, 0, xconvert[ranges[i].ss.ff], yconvert[ranges[i].ss.ss])+dist);
        debug(segtree);
    }

    fout << 2*n - max2d(segtree, 0, 0, x, y);

    return 0;
}