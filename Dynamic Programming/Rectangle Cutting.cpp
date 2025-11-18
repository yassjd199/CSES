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





void testcase() {
    int A , B;
    cin >> A >> B;
    vector<vii> dp(A + 1 , vii(B + 1 , 10000));
    for (int i = 0; i <= min(A , B); i++) {
        dp[i][i] = 0;
    }

    // when a==b then we dont need to anything so that is our base case , (dp[i][i] = 0 , i<= min(a,b))
    // otherwise lets  try to make a cut on a or b : 
    // for example if we cut on b we get 2 rectangles (a,c) and (a,b-c) 
    // so dp[a][b] = min(dp[a][b] , 1+ dp[a][c]+dp[a][b-c]) (dont forget the a part ) and thats it ; 
   // Time complexity O(500^3) 
    //  By the way only the iterative solution did pass the time limt 
    for (int a = 1; a <= A; a++) {
        for (int b = 1; b <= B; b++) {
            for (int c = 1; c <= 500; c++) {
                if (a > c)
                    dp[a][b] = min(dp[a][b] , 1 + dp[a - c][b] + dp[c][b]);
                if (b > c)
                    dp[a][b] = min(dp[a][b] , 1 + dp[a][b - c] + dp[a][c]);
            }
        }
    }

    // dbg(dp);
    cout << dp[A][B];


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
