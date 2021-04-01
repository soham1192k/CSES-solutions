#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e6+2;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;    
}
void solve(){   
    int n;cin>>n;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int pos=1;
    int cnt=1;
    int currend=v[0].second;
    while(pos<n){
        while(pos<n&&v[pos].first<currend){
            pos++;
        }
        if(pos<n){
            cnt++;
            currend=v[pos].second;
            pos++;
        }
    }
    cout<<cnt;
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
