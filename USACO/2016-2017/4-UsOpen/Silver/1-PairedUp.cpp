#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Check if the given threshold allows all the cows to form a pair
bool bisearch(deque<pair<int,int>> pairs, int thres){
    while (pairs.size()){
        if (pairs.front().first + pairs.back().first <= thres){
            int cancel = min(pairs.front().second, pairs.back().second);
            if (pairs.front().second <= cancel)
                pairs.pop_front();
            else
                pairs.front().second -= cancel;
            if (pairs.size() && pairs.back().second <= cancel)
                pairs.pop_back();
            else
                pairs.back().second -= cancel;
        }else{
            while (pairs.size()) {
                pairs.pop_front();
            }
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("pairup.out");
    ifstream fin("pairup.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        cows[i] = make_pair(b,a);
    }

    //Sort the input, convert it to a deque
    //Binary search on the answer.
    sort(cows.begin(),cows.end());
    deque<pair<int,int>> pairs;
    for (int i = 0; i < n; i++){
        pairs.push_back(cows[i]);
    }
    int a = 0, b = INT_MAX;
    while ((b-a)>1){
        if (bisearch(pairs, (a+b)/2)){
            b -= (b-a)/2;
        }else{
            a += (b-a)/2;
        }
    }
    if (!bisearch(pairs,a)) a = b;

    //Output
    fout << a;

    return 0;
}