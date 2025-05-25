/**
 * Created on: 2025-05-25
 * Author: yassjd199
 * Nested Ranges Count
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int , int> pii;
typedef pair<long long , long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon( );
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll long long int
#define ull unsigned long long int
const int dx[4] = { 0, 0, -1, 1 } , dy[4] = { -1, 1, 0, 0 };
// const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1 , M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> using Set = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template<typename K , typename V> using Map = tree<K , V , less<K> , rb_tree_tag , tree_order_statistics_node_update>;

void dbg_out( ) {
    cerr << endl;
}
template <typename Head , typename... Tail>
void dbg_out(Head H , Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void compress(vector<ll>& a , int start = 0) {
    int n = a.size( );
    vector<pair<ll , ll>>pairs(n);
    for (int i = 0; i < n; i++) {
        pairs[i] = { a[i],i };
    }
    sort(pairs.begin( ) , pairs.end( ));
    int nxt = start;
    for (int i = 0; i < n; i++) {
        if (i > 0 && pairs[i - 1].first != pairs[i].first) {
            nxt++;
        }
        a[pairs[i].second] = nxt;
    }
}

// 1-indexed BIT
ll fn[N];
void inc(int x , ll val) {
    for (; x < N; x += x & (-x)) fn[x] += val;
}
ll query(int x) {
    ll res = 0ll;
    for (; x; x -= x & (-x)) res += fn[x];
    return res;
}
ll query(int l , int r) {
    return l == 0 ? query(r) : query(r) - query(l - 1);
}





void testcase( ) {
    int n; cin >> n;
    vector<vll> v;
    vll l(n) , r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    compress(l);
    compress(r);
    for (int i = 0; i < n; i++) v.pb({ r[i],l[i],i });
    // it all about range sorting then once having right increasing or dercreasing figure out the answer 
    sort(all(v) , [&] (vll& a , vll& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];

    });
    vii ans1(n) , ans2(n);
    for (int i = 0; i < n; i++) {
        int left = v[i][1] , idx = v[i][2];
        ans1[idx] = query(left + 1 , n);
        inc(left + 1 , 1);
    }

    for (int i = 0; i < n; i++) cout << ans1[i] << " ";
    cout << endl;

    fill(fn , fn + n + 1 , 0);

    sort(all(v) , [&] (vll& a , vll& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    for (int i = 0; i < n; i++) {
        int left = v[i][1] , idx = v[i][2];
        ans2[idx] = query(left + 1);
        inc(left + 1 , 1);

    }
    for (int i = 0; i < n; i++) cout << ans2[i] << " ";



}


int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int _ = 1;
    // int __ = 1;
    clock_t z = clock( );
    // cin >> _;

    while (_--) {
        // cout << "Case #" << __++ << ": ";
        testcase( );
    }

    cerr << endl << "Run Time: " << ((double)(clock( ) - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
