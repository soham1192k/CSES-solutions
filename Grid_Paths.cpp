#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    if(v[0][0]=='*'||v[n-1][n-1]=='*') {cout<<0;return;}
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            if(v[i][j]=='*') dp[i][j]=0;
            else{
                if(i==0) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                else if(j==0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                else dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n-1][n-1];
}  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}