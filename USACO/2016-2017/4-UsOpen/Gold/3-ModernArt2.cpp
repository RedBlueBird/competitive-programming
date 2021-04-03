#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("art2.out");
    ifstream fin("art2.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> colors(n);
    vector<pii> ranges(n);
    for (int i = 0; i < n; i++) {
        fin >> colors[i];
        ranges[i] = make_pair(INT_MAX, 0);
    }

    //Since each color is only 1 stroke and is continuous,
    //we can mark the beginning and the ending of each color
    //The maximum overlap can be dealt with using prefix sum.
    //The painting is invalid if two ranges only intersect but not fully contained
    //This can be checked like how you check a string of "(()())" is valid
    for (int i = 0; i < n; i++){
        ranges[colors[i]].ff = min(ranges[colors[i]].ff, i);
        ranges[colors[i]].ss = max(ranges[colors[i]].ss, i);
    }
    vector<int> psum(n+1);
    vector<int> mark(n, 0);
    for (int i = 1; i < n; i++){
        if (ranges[i] == make_pair(INT_MAX, 0)) continue;
        psum[ranges[i].ff]++;
        psum[ranges[i].ss+1]--;
        if (ranges[i].ff != ranges[i].ss) {
            mark[ranges[i].ff] = 1;
            mark[ranges[i].ss] = 2;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++){
        psum[i] += psum[i-1];
        ans = max(ans, psum[i]);
    }
    stack<int> check;
    for (int i = 0; i < n; i++){
        if (mark[i] == 1){
            check.push(i);
        }else if (mark[i] == 2){
            if (check.empty() || colors[check.top()] != colors[i]){
                ans = -1;
                break;
            }
            check.pop();
        }
    }

    //Output
    fout << ans;

    return 0;
}

