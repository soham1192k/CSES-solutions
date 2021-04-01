#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int dp[n][m+1];
    memset(dp,0,sizeof(dp));
    if(a[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }
    else{
        dp[0][a[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==0){
                if(j-1>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
            else{
                if(j==a[i]){
                    if(j-1>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    if(j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=m;i++){
        sum=(sum+dp[n-1][i])%mod;
    }
    cout<<sum;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
