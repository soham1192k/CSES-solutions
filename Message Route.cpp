//Soham
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+2;
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//***************************************************************************************************************************************************************
vector<int>adj[100005];
bool visited[100005];
int par[100005];
int n,m;
int dist[100005];
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    for(int i=1;i<=n;i++) dist[i]=1e18;
    queue<int>q;
    par[1]=-1;
    q.push(1ll);
    visited[1]=true;
    dist[1]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto edge:adj[curr]){
            if(!visited[edge]){
                visited[edge]=true;
                dist[edge]=1+dist[curr];
                par[edge]=curr;
                q.push(edge);
            }
        }
    }
    if(dist[n]==1e18) cout<<"IMPOSSIBLE";
    else{
        cout<<1+dist[n]<<'\n';
        int now=n;
        vector<int>hold;
        while(now!=-1){
            hold.push_back(now);
            now=par[now];
        }
        reverse(hold.begin(),hold.end());
        for(auto x:hold) cout<<x<<" ";
    }
}   
int32_t main(){
    soham1192k;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif  
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
