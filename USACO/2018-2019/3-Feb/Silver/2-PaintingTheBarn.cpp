#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Set up the graph
int graph[1002][1002];

int main() {
    ofstream fout("paintbarn.out");
    ifstream fin("paintbarn.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs while also constructing the 2d difference matrix
    int n, k;
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        int a,b,c,d;
        fin >>a>>b>>c>>d;
        a++;b++;c++;d++;
        graph[a][b]++;
        graph[c][d]++;
        graph[a][d]--;
        graph[c][b]--;
    }

    //Recreate the original matrix from the 2d difference matrix
    //Add the tile to the answer if its sum equal k
    int ans = 0;
    for (int i = 1; i < 1002; i++){
        for (int j = 1; j < 1002; j++){
            graph[i][j] += graph[i-1][j]+graph[i][j-1]-graph[i-1][j-1];
            if (graph[i][j] == k) ans++;
        }
    }

    //Output
    fout << ans;

    return 0;
}