#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.first<b.first;    
}
void solve(){   
    int n;cin>>n;
    vector<pair<int,bool>>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,true});
        v.push_back({b,false});
    }
    sort(v.begin(),v.end());
    int maxx=-1e9;int curr=0;
    for(int i=0;i<2*n;i++){
        if(v[i].second){
            curr++;maxx=max(maxx,curr);
        }
        else{
            curr--;
        }
    }
    cout<<maxx;
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
