#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
            b--;
        }
        else{
            a=(a*a)%mod;
            b=b>>1;
        }
    }
    return ans;
}
void solve(){
    int a,b;cin>>a>>b;
    cout<<power(a,b)<<'\n';
}   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}