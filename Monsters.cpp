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
int n,m;
int rownum[4]={-1,0,0,1};
int colnum[4]={0,-1,1,0};
bool visited[1001][1001];
int dist[1001][1001];
int dist1[1001][1001];
pair<int,int> par[1001][1001];
bool ok(int r,int c){
    return r>=0&&r<n&&c>=0&&c<m;
}
void solve(){
    cin>>n>>m;
    queue<pair<int,int>>q,qq;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist[i][j]=1e18;
    }
    int posx=-1;int posy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='M') {q.push({i,j});visited[i][j]=true;dist[i][j]=0;}
            else if(v[i][j]=='A') {qq.push({i,j});posx=i;posy=j;}
        } 
    }
    while(!q.empty()){
        pair<int,int>curr=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=rownum[i]+curr.first;
            int nc=curr.second+colnum[i];
            if(ok(nr,nc)&&!visited[nr][nc]&&v[nr][nc]!='#'){
                visited[nr][nc]=true;
                dist[nr][nc]=1+dist[curr.first][curr.second];
                q.push({nr,nc});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist1[i][j]=1e18;
    }
    memset(visited,false,sizeof(visited));
    dist1[posx][posy]=0;
    visited[posx][posy]=true;
    par[posx][posy]={-1,-1};
    while(!qq.empty()){
        pair<int,int>curr=qq.front();
        qq.pop();
        for(int i=0;i<4;i++){
            int nr=rownum[i]+curr.first;
            int nc=colnum[i]+curr.second;
            if(ok(nr,nc)&&!visited[nr][nc]&&v[nr][nc]!='#'){
                visited[nr][nc]=true;
                dist1[nr][nc]=1+dist1[curr.first][curr.second];
                qq.push({nr,nc});
                par[nr][nc]=curr;
            }
        }
    }
    int destx=-1,desty=-1;bool flag=false;
    for(int j=0;j<m;j++){
        if(dist1[0][j]<dist[0][j]){
            cout<<"YES"<<'\n'<<dist1[0][j]<<'\n';
            destx=0;
            desty=j;
            flag=true;
        }
    }
    if(!flag){
        for(int j=0;j<m;j++){
            if(dist[n-1][j]>dist1[n-1][j]){
                cout<<"YES"<<'\n'<<dist1[n-1][j]<<'\n';
                destx=n-1;
                desty=j;
                flag=true;
            }
        }
    }
    if(!flag){
        for(int i=0;i<n;i++){
            if(dist[i][0]>dist1[i][0]){
                cout<<"YES"<<'\n'<<dist1[i][0]<<'\n';
                destx=i;
                desty=0;
                flag=true;
            }
        }
    }
    if(!flag){
        for(int i=0;i<n;i++){
            if(dist[i][m-1]>dist1[i][m-1]){
                cout<<"YES"<<'\n'<<dist1[i][m-1]<<'\n';
                destx=i;
                desty=m-1;
                flag=true;
            }
        }
    }
    if(!flag)
    cout<<"NO\n";
    else{
        string ans="";
        while(destx!=posx||desty!=posy){
            int px=par[destx][desty].first;
            int py=par[destx][desty].second;
            if(px==destx&&py>desty){
                ans+="L";
            }
            else if(px==destx&&py<desty){
                ans+="R";
            }
            else if(px>destx&&py==desty){
                ans+="U";
            }
            else ans+="D";
            destx=px;
            desty=py;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
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
