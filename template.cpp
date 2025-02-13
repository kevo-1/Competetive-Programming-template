#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <map>
#include <functional>
using namespace std;

#define kevo ios_base::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9+7;

/***************************************Sparse Table****************************************/
struct SparseTable{
    int N;
    vector<vector<int>> lookup;
    SparseTable(int n) {
        N = n;
        int P = floor(log2(N)) + 1;
        lookup.resize(P, vector<int>(N,0));
    }
    int operation(int x, int y) {
        return gcd(x,y);
    }
    void build(vector<int>& vec) {
        for (int i = 0; i < N; i++) {
            lookup[0][i] = vec[i];
        }
        for (int i = 1; (1 << i) <= N; i++) {
            for (int j = 0; (j + (1 << i) - 1) < N; j++) {
                lookup[i][j] = operation(lookup[i-1][j], lookup[i-1][j + (1 << (i-1))]);
            }
        }
    }
    int query(int l, int r) {
        int cur = r-l+1;
        int k = floor(log2(cur));
        return operation(lookup[k][l], lookup[k][r-(1<<k)+1]);
    }
};
/*******************************************************************************************/

/***************************************Segment Tree****************************************/
struct SegmentTree{
    int N;
    vector<int> tree;
    SegmentTree(int n){
        N = 1;
        while(N < n) N<<=1;
        tree.resize(N<<1);
    }
};
/*******************************************************************************************/


/*************************************start † here******************************************/

void solve() {
    //write code here
}

int main() {
    kevo
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
/***************************************End † here******************************************/
