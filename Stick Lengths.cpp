#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int med=0;
    for(int& x:a) cin>>x;
    sort(a.begin(),a.end());
    if(n==1) {cout<<0;return;}
    if(n%2==1){
        med=(n-1)/2;
    }
    else med=n/2-1;
    int median=a[med];int cost=0;
    for(int i=0;i<n;i++){
        cost+=abs(a[i]-median);
    }
    cout<<cost;
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
