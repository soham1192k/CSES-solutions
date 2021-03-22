#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>c(n);
    for(int& y:c) cin>>y;
    int dp[x+1];
    for(int i=0;i<=x;i++) dp[i]=1e9;
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(c[j]<=i) 
            dp[i]=min(dp[i],1+dp[i-c[j]]);
        }
    }
    if(dp[x]==1e9) cout<<-1;
    else 
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