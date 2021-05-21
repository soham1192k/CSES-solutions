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
struct Edge{
    int a,b,cost;
};
int n,m;
vector<Edge>edges;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        Edge now;
        now.a=u;
        now.b=v;
        now.cost=w;
        edges.push_back(now);
    }
    vector<int>d(n+1,0);
    vector<int>p(n+1,-1);
    int x;
    for(int i=0;i<n;i++){
        x=-1;
        for(Edge e:edges){
            if(d[e.a]+e.cost<d[e.b]){
                d[e.b]=d[e.a]+e.cost;
                p[e.b]=e.a;
                x=e.b;
            }
        }
    }   
    if(x==-1){
        cout<<"NO";return;
    }
    for(int i=0;i<n;i++){
        x=p[x];
    }
    vector<int>cycle;
    for(int v=x;;v=p[v]){
        cycle.push_back(v);
        if(v==x&&cycle.size()>1)
        break;
    }
    reverse(cycle.begin(),cycle.end());
    cout<<"YES\n";
    for(int v:cycle)
    cout<<v<<" ";
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
