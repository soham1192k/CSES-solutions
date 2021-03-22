#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mxN=10005;
void solve(){
    string s;cin>>s;
    sort(s.begin(),s.end());
    int cnt=0;
    vector<char>v;
    vector<string>ans;
    for(auto x:s) v.push_back(x);
    do{
        cnt++;
        string temp="";
        for(auto x:v) temp+=x;
        ans.push_back(temp);
    }while(next_permutation(v.begin(),v.end()));
    cout<<cnt<<'\n';
    for(auto x:ans) cout<<x<<'\n';
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