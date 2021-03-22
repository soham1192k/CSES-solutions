#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    if(n==1) {cout<<"1";return;}
    if(n<=3) {cout<<"NO SOLUTION";return;}
    if(n==4) {cout<<"2 4 1 3";return;}
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
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