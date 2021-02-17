#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

//Perform multi-source bfs. Pies can be thought as nodes
//A node from Bessie can have an edge to a node from Elsie if tastiness difference <= D in Elsie's standard. Vice versa
//Since manually constructing all the edges takes N^2 time, we can use Sets to let searching to be faster
//Nodes with tastiness of 0 will have outdegree of 0, they will be the source nodes since they terminates the pie-exchange.
//For a node A in set Bessie, search all the nodes in set Elsie such that it met the D requirement.
//Then remove node A, since it is already "visited".
void bfs(set<tuple<int,int,int>> pie1, set<tuple<int,int,int>> pie2, vector<int>& dist1, vector<int>& dist2, int d){
    set<int> curr;
    for (auto i: pie1){
        int a,b,c;
        tie(a,b,c) = i;
        if (a == 0) {
            curr.insert(b);
            dist1[c] = 1;
        }
    }
    int dist = 2;
    while (curr.size()){
        set<int> next;
        while (curr.size()){
            int node = *curr.begin();
            curr.erase(curr.begin());
            while (true){
                auto ptr = pie2.lower_bound(make_tuple(node,INT_MIN,INT_MIN));
                if (ptr != pie2.end() && node - get<0>(*ptr) >= -d) {
                    pie2.erase(ptr);
                    if (dist2[get<2>(*ptr)] > dist) {
                        dist2[get<2>(*ptr)] = dist;
                        next.insert(get<1>(*ptr));
                    }
                }else{
                    break;
                }
            }
        }
        swap(curr,next);
        swap(pie1,pie2);
        swap(dist1,dist2);
        dist++;
    }
    if (dist%2){
        swap(dist1,dist2);
    }
}

int main() {
    ofstream fout("piepie.out");
    ifstream fin("piepie.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct two vector tuple that stores the tastiness of each pie
    int n, d;
    fin >> n >> d;
    set<tuple<int,int,int>> bessie;
    set<tuple<int,int,int>> elsie;
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        bessie.insert(make_tuple(-b,-a,i));
    }
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        elsie.insert(make_tuple(-a,-b,i));
    }

    //Bfs two times
    //One time starts with pies from Bessie, one time starts with pies from Elsie
    vector<int> distb(n, INT_MAX);
    vector<int> diste(n, INT_MAX);
    bfs(bessie,elsie,distb,diste,d);
    bfs(elsie,bessie,diste,distb,d);

    //Output the distance of each pie from Bessie
    //If the distance is INT_MAX, it means the pie was never touched, so -1
    for (int i: distb){
        if (i == INT_MAX){
            fout << -1 << "\n";
        }else {
            fout << i << "\n";
        }
    }

    return 0;
}

