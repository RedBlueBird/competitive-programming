#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, a,b;
    cin >> n;
    vector<vector<int>> ranges(n, vector<int>(3));
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        ranges[i] = vector<int>{a,b,i};
    }

    vector<int> sofar;
    vector<int> contained(n, 0);
    vector<int> covered(n,0);
    sort(ranges.begin(), ranges.end(), cmp);
    for (int i = 0; i < n; i++){
        int a = 0, b = sofar.size()-1;
        while ((b-a)>1){
            if (sofar[(a+b)/2] > ranges[i][1]){
                b -= (b-a)/2;
            }else{
                a += (b-a)/2;
            }
        }
        if (sofar.empty()){
            contained[i] = 0;
            continue;
        }
        if (ranges[i][1] == sofar[b]) a = b;
        contained[i] = a+1;
    }
    for (int i = 0; i < n; i++){
        cout << contained[i] << " ";
    }

    return 0;
}