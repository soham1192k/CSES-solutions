#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        if(i>=6) dp[i]=(dp[i]+dp[i-6])%mod;
        if(i>=5) dp[i]=(dp[i]+dp[i-5])%mod;
        if(i>=4) dp[i]=(dp[i]+dp[i-4])%mod;
        if(i>=3) dp[i]=(dp[i]+dp[i-3])%mod;
        if(i>=2) dp[i]=(dp[i]+dp[i-2])%mod;
        if(i>=1) dp[i]=(dp[i]+dp[i-1])%mod;
    }
    cout<<dp[n];
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