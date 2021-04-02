#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
void solve(){   
    int n;cin>>n;
    vector<int>a(n);int sum=0;
    for(int& x:a) {cin>>x;sum+=x;}
    sort(a.begin(),a.end());
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j-a[i-1]>=0)
            dp[i][j]|=dp[i-1][j-a[i-1]];
            dp[i][j]|=dp[i-1][j];
        }
    }
    set<int>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(dp[i][j]) s.insert(j);
        }
    }
    cout<<s.size()<<'\n';
    for(auto x:s) cout<<x<<" ";
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
