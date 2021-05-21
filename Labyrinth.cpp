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
bool visited[1001][1001];
int dist[1001][1001];
pair<int,int> par[1001][1001];
int rownum[4]={-1,0,0,1};
int colnum[4]={0,-1,1,0};
int n,m;
bool ok(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void solve(){
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    int posx=-1,posy=-1;
    int posxx=-1,posyy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            cin>>v[i][j];
            if(v[i][j]=='A'){
                posx=i;posy=j;
            }
            if(v[i][j]=='B'){
                posxx=i;
                posyy=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist[i][j]=1e18;
    }
    dist[posx][posy]=0;
    par[posx][posy]={-1,-1};
    queue<pair<int,int>>q;
    q.push({posx,posy});
    visited[posx][posy]=true;
    while(!q.empty()){
        pair<int,int>curr=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=rownum[i]+curr.first;
            int nc=colnum[i]+curr.second;
            if(ok(nr,nc)&&!visited[nr][nc]&&v[nr][nc]!='#'){
                visited[nr][nc]=true;
                dist[nr][nc]=1+dist[curr.first][curr.second];
                par[nr][nc]=curr;
                q.push({nr,nc});
            }
        }
    }
    if(!visited[posxx][posyy]) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<dist[posxx][posyy]<<'\n';
        int r=posxx;int c=posyy;
        string ans="";
        while(r!=-1&&c!=-1){
            int pr=par[r][c].first;
            int pc=par[r][c].second;
            if(pr==r&&pc-c==-1) ans+="R";
            else if(pr==r&&c-pc==-1) ans+="L";
            else if(pc==c&&pr-r==-1) ans+="D";
            else ans+="U";
            r=pr;c=pc;
        }
        reverse(ans.begin(),ans.end());
        for(int i=1;i<ans.length();i++) cout<<ans[i];
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
