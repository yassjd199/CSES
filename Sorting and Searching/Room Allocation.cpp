/**
 * Created on: 2025-05-27
 * Author: yassjd199
 * Room Allocation
 */
 
#include <bits/stdc++.h>
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
void dbg_out( ) {
    cerr << endl;
}
template <typename Head , typename... Tail>
void dbg_out(Head H , Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 

 
void testcase( ) {
    int n; cin >> n;
    vector<vii> v;
    vii ans(n);
    priority_queue <pii> pq;
    for(int i = 0 ; i<n ;i++){
        int l,r;cin>>l>>r;
        v.pb({l,r,i});
    }
    sort(all(v));
    int k=1;
    pq.push({0,1});
    for(int i=0;i<n;i++){
        int l=v[i][0] , r=v[i][1],idx = v[i][2];
        int room = pq.top().s,R=-pq.top().f;
        if(l>R){
            ans[idx]=room;
            pq.pop();
            pq.push({-r,room});
        }
        else{
            ans[idx]=++k;

            pq.push({-r,k});
        }
        

    }
    cout<<k<<endl;
    for(int i =0 ;i <n ;i++) cout<<ans[i]<<" ";

 
 
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
