#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int& x:a) cin>>x;
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]) ;
        else{
            ans+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
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