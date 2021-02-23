#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int Dx[4] = {0,0,1,-1};
int Dy[4] = {1,-1,0,0};
map<char,int> dir = {{'N',0},{'S',1},{'E',2},{'W',3}};

int main() {
    ofstream fout("mowing.out");
    ifstream fin("mowing.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<char,int>> input(n);
    for (int i = 0; i < n; i++){
        char a;
        int b;
        fin >> a >> b;
        input[i] = make_pair(a,b);
    }

    //Store each unique point and its timestamp into a map
    //Always keep the smallest time difference as the answer
    int x = 1;
    pii start = {0,0};
    map<pii,int> visited = {{{0,0},0}};
    int ans = -1;
    for (int k = 0; k < 1; k ++) {
        for (int i = 0; i < n; i++) {
            char a;
            int b;
            tie(a, b) = input[i];
            for (int j = 0; j < b; j++) {
                start.ff += Dx[dir[a]];
                start.ss += Dy[dir[a]];
                if (visited.count(start)) {
                    if (ans == -1)
                        ans = x - visited[start];
                    else
                        ans = min(ans, x - visited[start]);
                }
                visited[start] = x;
                x++;
            }
        }
    }

    //Output
    fout << ans;

    return 0;
}

