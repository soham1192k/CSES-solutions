#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    int dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=1e9;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j!=0){
            dp[i]=min(dp[i],1+dp[i-(j%10)]);
            j/=10;
        }
    }
    cout<<dp[n];
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
