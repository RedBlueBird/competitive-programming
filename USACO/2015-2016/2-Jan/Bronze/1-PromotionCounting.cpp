#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
    ofstream fout("promote.out");
    ifstream fin("promote.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    vector<pii> nums(4);
    for (int i = 0; i < 4; i++)
        fin >> nums[i].ff >> nums[i].ss;

    //Compute answer
    vector<int> ans(4);
    for (int i = 3; i > 0; i--){
        ans[i-1] = nums[i].ss - nums[i].ff + ans[i];
    }

    //Output
    for (int i = 0; i < 3; i++)
        fout << ans[i] << "\n";

    return 0;
}

