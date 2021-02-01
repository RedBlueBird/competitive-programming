#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("moop.out");
    ifstream fin("moop.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> particles(n);
    for (int i = 0; i <= n; i++){
        fin >> particles[i].first >> particles[i].second;
    }

    //Particle A is connected to B if A.x <= B.x && A.y <= B.y or vice versa
    //Two particles are in the same connected component if there is a path connected by some particles
    //All the unique connected components will contribute +1 to the answer since they can't affect each other
    //The connected components can be found less than O(n^2) time by sort by x value
    //Scan from left to right, if the minimum y-value particle seen so far is higher than the maximum y-value particle not seen yet
    //Then those are in two different connected components
    sort(particles.begin(), particles.end());
    vector<int> left(n+1, INT_MAX);
    vector<int> right(n+1, INT_MIN);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        left[i] = min(left[i-1], particles[i-1].second);
    for (int i = n-1; i >= 0; i--)
        right[i] = max(right[i+1], particles[i].second);
    for (int i = 1; i <= n; i++)
        if (left[i] > right[i])
            ans++;

    //Output
    fout << ans;

    return 0;
}