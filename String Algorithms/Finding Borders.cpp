/*
    @author : yassjd199
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



//dont forget to call pre();


const int P = 127;
const int MOD = 1e9 + 7;
int pw[N];

void pre( ) {
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = (1LL * pw[i - 1] * P) % MOD;
    }
}

struct Hash {
    vector<int> pref;
    Hash(const string& s) {
        int hash_val = 0;
        pref.resize((int)s.size( ));
        for (int i = 0; i < s.size( ); ++i) {
            hash_val = (1LL * hash_val * P) % MOD;
            hash_val = (hash_val + s[i]) % MOD;
            pref[i] = hash_val;
        }
    }

    int getHashValue(int l , int r) {
        int ret = pref[r];
        int sz = r - l + 1;
        --l;
        if (l >= 0) {
            ret -= (1LL * pref[l] * pw[sz]) % MOD;
            if (ret < 0) ret += MOD;
        }
        return ret;
    }
};






void testcase( ) {
    string str; cin >> str;

    Hash str_hash = Hash(str);


    int n = str.size( );

    for (int i = 0; i < n - 1; i++) {
        if (str_hash.getHashValue(0 , i) == str_hash.getHashValue(n - 1 - i , n - 1)) {
            cout << i + 1 << " ";
        }
    }










}

int main( ) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre( );
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
