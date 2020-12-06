#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("rental.out");
    ifstream fin("rental.in");
//    ofstream fout ("../output.txt");
//    ifstream fin ("../input.txt");

    //Take inputs
    int n, m, r;
    fin >> n >> m >> r;
    vector<int> cows(n);
    vector<pair<int,ll>> gal(m);
    vector<int> sell(r);
    ll gals = 0;
    for (int i = 0; i < n; i++){
        fin >> cows[i];
        gals += cows[i];
    }
    for (int i = 0; i < m; i++){
        fin >> gal[i].second >> gal[i].first;
    }
    for (int i = 0; i < r; i++){
        fin >> sell[i];
    }
    sort(cows.begin(), cows.end());
    sort(gal.begin(), gal.end());
    sort(sell.begin(), sell.end());

    //Find the profit from selling all possible cows and the milk from left over to the highest bidders
    //Then find the profit from selling n-1 least productive cows and left over milk to the highest bidders
    //Until all cows are sold for milk.
    //The highest profit among all the profits is the answer.
    ll ans = 0;
    ll gained = 0;
    int a = min(r, n)-1;
    int b = m-1;
    for (int i = 0; i <= a; i++){
        gained += sell[r-i-1];
        gals -= cows[i];
    }
    for (int j = b; j >= 0; j--) {
        int k = min(gal[j].second, gals);
        gained += gal[j].first * k;
        gal[j].second -= k;
        gals -= k;
        b = j;
        if (gals == 0){
            break;
        }
    }
    ans = max(gained, ans);
    while (true) {
        gained -= sell[r-a-1];
        gals += cows[a--];

        for (int j = b; j >= 0; j--) {
            int k = min(gal[j].second, gals);
            gained += gal[j].first * k;
            gal[j].second -= k;
            gals -= k;
            b = j;
            if (gals == 0){
                break;
            }
        }

        ans = max(gained, ans);
        if (gal[0].second == 0 || a == -1){
            break;
        }
    }

    //Output
    fout << ans;

    return 0;
}