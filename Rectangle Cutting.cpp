#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int a,b;cin>>a>>b;
    int dp[a+1][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j) dp[i][j]=0;
            else dp[i][j]=1e9; 
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) continue;
            else{
                for(int cut=1;cut<=i-1;cut++){
                    dp[i][j]=min(dp[i][j],1+dp[cut][j]+dp[i-cut][j]);
                }
                for(int cut=1;cut<=j-1;cut++){
                    dp[i][j]=min(dp[i][j],1+dp[i][cut]+dp[i][j-cut]);
                }
            }
        }
    }
    cout<<dp[a][b];
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
