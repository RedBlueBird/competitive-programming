#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, q;
    cin >> n >> q;
    vector<int> graph(n+1);
    for (int i = 1; i <= n; i++){
        cin >> graph[i];
    }

    vector<vector<int>> succ(31, vector<int>(n+1));
    for (int i = 0; i <= 30; i++){
        for (int j = 1; j <= n; j++){
            if (i == 0){
                succ[i][j] = j;
            }else if (i == 1){
                succ[i][j] = graph[j];
            }else{
                succ[i][j] = succ[i-1][succ[i-1][j]];
            }
        }
    }
//    for (int i = 0; i <= 30; i++){
//        for (int j = 1; j <= n; j++){
//            cout << succ[i][j] << " ";
//        }
//        cout << " \n";
//    }
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        int node = a;
        int jump = b;
        while (jump){
            int gap = int(log2(jump));
            node = succ[gap][node];
            jump -= gap;
            if (jump == 1){
                node = graph[node];
                break;
            }
        }
        cout << node << "\n";
    }

    return 0;
}