#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

//Sort the points by their y values
bool ycompress(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

//Return the total points in a rectangle with 2d prefix sum matrix
int total(vector<vector<int>>& psum, int x1, int y1, int x2, int y2){
    return psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1];
}

int main() {
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }

    //Compress the cow coordinates since all x,y values are unique
    //Add them into a prefix map
    //The total pairs possible to be formed between any two points a,b where a_y <= b_y
    //is the amount of points to the left of min(a_x,b_x) times the amount of points to the right of max(a_x,b_x)
    //Iterate through all the pairs in o(n^2) and add the products to the answer
    vector<vector<int>> psum(n+1, vector<int>(n+1,0));
    ll ans = 0;
    sort(cows.begin(),cows.end());
    for (int i = 0; i < n; i++)
        cows[i].first = i;
    sort(cows.begin(),cows.end(),ycompress);
    for (int i = 0; i < n; i++)
        cows[i].second = i;
    for (int i = 0; i < n; i++)
        psum[cows[i].first+1][cows[i].second+1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++){
            int left = min(cows[i].first, cows[j].first)+1;
            int right = max(cows[i].first, cows[j].first)+1;
            ans += total(psum, 1, i+1, left, j+1) * total(psum, right, i+1, n, j+1);
        }

    //Output, +1 to include the empty subset
    cout << ans + 1;

    return 0;
}