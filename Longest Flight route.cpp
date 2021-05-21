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
int n,m;
vector<int>hold;
int par[100005];
void kahn(vector<int>&indegree){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int curr=q.front();
        hold.push_back(curr);
        q.pop();
        for(auto edge:adj[curr]){
            indegree[edge]--;
            if(indegree[edge]==0) q.push(edge);
        }
    }
}
void solve(){
    cin>>n>>m;
    vector<int>indegree(n+1,0);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    kahn(indegree);
    if(hold.size()!=n) {cout<<"IMPOSSIBLE\n";return;}
    int dp[n+1];
    for(int i=1;i<=n;i++) dp[i]=-1e18;
    memset(par,-1,sizeof(par));
    dp[1]=1;par[1]=-1;
    for(int i=0;i<=n-2;i++){
        for(auto edge:adj[hold[i]]){
            if(dp[edge]<1+dp[hold[i]]){
                dp[edge]=1+dp[hold[i]];
                par[edge]=hold[i];
            }
        }
    }
    if(dp[n]<=0) {cout<<"IMPOSSIBLE\n";return;}
    cout<<dp[n]<<'\n';
    int curr=n;
    vector<int>ans;
    while(curr!=-1){
        ans.push_back(curr);
        curr=par[curr];
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<" ";
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
