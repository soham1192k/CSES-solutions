#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    string s;cin>>s;
    int n=s.length();
    int pos=1;
    int maxx=1;
    int curr=1;
    char prev=s[0];
    while(pos<n){
        if(s[pos]==prev){
            curr++;
        }
        else{
            maxx=max(maxx,curr);
            curr=1;
        }
        prev=s[pos++];
    }
    maxx=max(maxx,curr);
    cout<<maxx;
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