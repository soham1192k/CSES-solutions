#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n,x;cin>>n>>x;
    vector<int>h(n),s(n);
    for(int& xx:h) cin>>xx;
    for(int& xx:s) cin>>xx;
    vector<int>dp(x+1,0);
    for(int i=1;i<=n;i++){
        vector<int>n_dp(x+1);
        for(int j=1;j<=x;j++){
            if(j-h[i-1]>=0)
            n_dp[j]=max(dp[j-h[i-1]]+s[i-1],dp[j]);
            else n_dp[j]=dp[j];
        }
        dp=n_dp;
    }
    int maxx=-1;
    for(int i=0;i<=x;i++){
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx;
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
