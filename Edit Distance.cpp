#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    string s,t;cin>>s>>t;
    int n=s.length();
    int m=t.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));   
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }   
            else{
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n][m];
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
