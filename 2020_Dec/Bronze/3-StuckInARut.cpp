#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> upcow;
    vector<vector<int>> leftcow;
    for (int i = 0; i < n; i++){
        char a;
        cin >> a;
        int b,c;
        cin >> b >> c;
        if (a == 'E'){
            leftcow.push_back(vector<int>{c,b,i});
        }
        else{
            upcow.push_back(vector<int>{b,c,i});
        }
    }

    //Find all intersections between the north cow and the east cow.
    //If the cow has already been blocked by others, they can no longer block cows even if they could
    //If the cow blocked all other cows, its grass will be infinity
    //No two cows in the same direction shares the same lane.
    vector<int> ans(n);
    sort(leftcow.begin(),leftcow.end());
    sort(upcow.begin(),upcow.end());
    vector<int> upstop(n, INT_MAX);
    vector<int> leftstop(n, INT_MAX);
    for (int i = 0; i < upcow.size(); i++){
        for (int j = 0; j < leftcow.size(); j++){
//            if (i != 0 && upcow[i][0] == upcow[i-1][0] && upstop[upcow[i-1][2]] >= upcow[i][1]){
//                upstop[upcow[i-1][2]] = upcow[i][1]-1;
//                ans[upcow[i-1][2]] = upcow[i][1] - upcow[i-1][1];
//            }
            if (upcow[i][0] >= leftcow[j][1] && upcow[i][1] <= leftcow[j][0] && leftstop[leftcow[j][2]] >= upcow[i][0]){
                if (upcow[i][0] - leftcow[j][1] < leftcow[j][0] - upcow[i][1]){
                    upstop[upcow[i][2]] = leftcow[j][0];
                    ans[upcow[i][2]] = leftcow[j][0] - upcow[i][1];
                    break;
                }
                else if (upcow[i][0] - leftcow[j][1] > leftcow[j][0] - upcow[i][1]){
                    leftstop[leftcow[j][2]] = min(leftstop[leftcow[j][2]],upcow[i][0]);
                }
            }
            if (j == leftcow.size()-1){
                ans[upcow[i][2]] = -1;
            }
        }
    }
    for (int i = 0; i < leftcow.size(); i++){
        for (int j = 0; j < upcow.size(); j++){
//            if (i != 0 && leftcow[i][0] == leftcow[i-1][0] && leftstop[leftcow[i-1][2]] >= leftcow[i][1]){
//                leftstop[leftcow[i-1][2]] = leftcow[i][1]-1;
//                ans[leftcow[i-1][2]] = leftcow[i][1] - leftcow[i-1][1];
//            }
            if (upcow[j][0] >= leftcow[i][1] && upcow[j][1] <= leftcow[i][0] && upstop[upcow[j][2]] >= leftcow[i][0]){
                if (upcow[j][0] - leftcow[i][1] > leftcow[i][0] - upcow[j][1]){
                    leftstop[leftcow[i][2]] = upcow[j][0];
                    ans[leftcow[i][2]] = upcow[j][0] - leftcow[i][1];
                    break;
                }
                else if (upcow[j][0] - leftcow[i][1] < leftcow[i][0] - upcow[j][1]){
                    upstop[upcow[j][2]] = min(upstop[upcow[j][2]],leftcow[i][0]);
                }
            }
            if (j == upcow.size()-1){
                ans[leftcow[i][2]] = -1;
            }
        }
    }

    //Output
    for (int i: ans){
        if (i == -1) cout << "Infinity\n";
        else cout << i << "\n";
    }

    return 0;
}