#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    int ans=0;
    int prod=5;
    while(true){
        int new_add=n/prod;
        prod*=5;
        ans+=new_add;
        if(new_add==0) break;
    }
    cout<<ans;
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