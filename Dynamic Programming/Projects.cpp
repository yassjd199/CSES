/**
 * Author: yassjd199
 *
 *
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 // namespace __DEBUG_UTIL__
#ifndef ONLINE_JUDGE
#include "debugTemplate.h"
#define dbg(...)                                            \
        std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgArr(...)                                         \
        std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", \
            __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define dbgArr(...)
#endif
using namespace __gnu_pbds;
using namespace std;
typedef pair<int , int> pii; typedef pair<long long , long long> pll; typedef vector<int> vii; typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon();
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll long long int
#define ull unsigned long long int
const int dx[4] = { 0, 0, -1, 1 } , dy[4] = { -1, 1, 0, 0 };
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int N = 1e6 + 1 , M = 30 , MOD = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T>
using Set = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template <typename K , typename V>
using Map = tree<K , V , less<K> , rb_tree_tag , tree_order_statistics_node_update>;


ll st[4 * N];
ll merg(ll l , ll r) {
    return max(l , r);
}

int n;

void upd(int pos , ll val , int cur = 0 , int s = 0 , int e = n) {
    if (s == e) {
        st[cur] = val;
        return;
    }
    int m = (s + e) >> 1;
    (pos <= m) ? upd(pos , val , 2 * cur + 1 , s , m) : upd(pos , val , 2 * cur + 2 , m + 1 , e);
    st[cur] = merg(st[2 * cur + 1] , st[2 * cur + 2]);
}

ll query(int l , int r , int cur = 0 , int s = 0 , int e = n) {
    if (e < l || s > r) return 0ll;
    if (s >= l && e <= r) {
        return st[cur];
    }
    int m = (s + e) >> 1;
    return merg(query(l , r , 2 * cur + 1 , s , m) , query(l , r , 2 * cur + 2 , m + 1 , e));
}



void testcase() {
    n; cin >> n;
    vector<vll> A(n);
    for (int i = 0; i < n; i++) {
        ll L , R , C;
        cin >> L >> R >> C;
        A[i] = { R,L,C };
    }

    sort(all(A));

    vll dp(n + 1);
    vll L(n) , R(n) , C(n);
    for (int i = 0; i < n; i++) {
        R[i] = A[i][0];
        L[i] = A[i][1];
        C[i] = A[i][2];
    }

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(all(R) , L[i - 1]) - R.begin();
        dp[i] = C[i - 1] + query(0 , pos);
        upd(i , dp[i]);
    }

    cout << *max_element(all(dp)) << endl;



}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int _ = 1;
    // int __ = 1;
    clock_t z = clock();
    // cin >> _;

    while (_--) {
        // cout << "Case #" << __++ << ": ";
        testcase();
    }

    cerr << endl << "Run Time: " << ((double) (clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
