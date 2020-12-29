#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define mii map<int,int>
#define vi vector<int>
#define vb vector<bool>
#define f first
#define s second
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
using namespace std;

bool cmp(pii a, pii b){
    return a.s < b.s;
}

int main() {
//    ofstream fout("triangles.out");
//    ifstream fin("triangles.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vii nums(n);
    FOR(i,0,n)
        fin >> nums[i].f >> nums[i].s;

    mii verts;
    mii vertt;
    mii vertdp;
    mii horzs;
    mii horzt;
    mii horzdp;
    sort(nums.begin(), nums.end());
    FOR(i,0,n){
        if (!verts.count(nums[i].f))
            verts[nums[i].f] = nums[i].s;
        else
            vertt[nums[i].f] += nums[i].s - verts[nums[i].f];
    }
    FOR(i,1,n-1){
        while(i<n && nums[i].f==nums[i-1].f){
            vertdp[nums[i].s] = vertdp[nums[i-1].s] + 1; //???????
        }
    }
    sort(nums.begin(), nums.end(), cmp);
    FOR(i,0,n){
        if (!horzs.count(nums[i].s))
            horzs[nums[i].s] = nums[i].f;
        else
            horzt[nums[i].s] += nums[i].f - horzs[nums[i].s];
    }


    return 0;
}