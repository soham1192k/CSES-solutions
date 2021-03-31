#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n);
    for(int& xx:a) cin>>xx;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int check=x-a[i];
        if(mp[check]!=0){
            cout<<mp[check]<<" "<<i+1;
            return;
        }
        mp[a[i]]=i+1;
    }
    cout<<-1;
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
