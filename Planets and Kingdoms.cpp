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
const int mxN=2e5+1;
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
//******************************************************************************************************************************************
vector<int>adj[100005],adj_r[100005];
int n,m;
bool visited[100005];
vector<int>order,component;
int cc;
int id[100005];
void dfs1(int v){
    visited[v]=true;
    for(auto edge:adj[v]){
        if(!visited[edge]) dfs1(edge);
    }
    order.push_back(v);
}
void dfs2(int v,int val){
    visited[v]=true;
    id[v]=val;
    component.push_back(v);
    for(auto edge:adj_r[v]){
        if(!visited[edge]) dfs2(edge,val);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj_r[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs1(i);
    }
    memset(visited,false,sizeof(visited));
    reverse(order.begin(),order.end());
    for(auto v:order){
        if(!visited[v]){
            ++cc;
            dfs2(v,cc);
            component.clear();
        }
    }
    cout<<cc<<'\n';
    for(int i=1;i<=n;i++) cout<<id[i]<<" ";
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
