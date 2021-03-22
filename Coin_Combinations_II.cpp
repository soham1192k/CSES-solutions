#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>c(n);
    for(int& x:c) cin>>x;
    int dp[x+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int j=0;j<n;j++){
        for(int i=1;i<=x;i++){
            if(c[j]<=i)
            dp[i]=(dp[i]+dp[i-c[j]])%mod;
        }
    }
    cout<<dp[x];
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