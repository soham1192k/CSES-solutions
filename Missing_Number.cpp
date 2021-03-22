#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    int n;cin>>n;
    vector<int>a(n-1);
    int sum=0;
    for(int& x:a) {cin>>x;sum+=x;}
    int s=n*(n+1)/2;
    cout<<s-sum;
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