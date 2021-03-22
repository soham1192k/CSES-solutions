#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
int power(int a,int b,int m){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
            b--;
        }
        else{
            a=(a*a)%m;
            b=b>>1;
        }
    }
    return ans; 
}
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int y=power(b,c,mod-1);
    cout<<power(a,y,mod)<<'\n';
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