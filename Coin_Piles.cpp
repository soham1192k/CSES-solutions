#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int a,b;cin>>a>>b;
    if((a+b)%3!=0) {cout<<"NO\n";return;}
    if(min(a,b)>=(a+b)/3) {cout<<"YES\n";return;}
    cout<<"NO\n";
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