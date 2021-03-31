#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n,x;cin>>n>>x;
    multiset<int>s;int cnt=0;
    for(int i=0;i<n;i++) {int xx;cin>>xx;s.insert(xx);}
    while(s.size()!=0){
        int curr=*(s.begin());
        auto itr=s.begin();
        s.erase(itr);
        auto itr1=s.upper_bound(x-curr);
        if(itr1!=s.begin()){
            itr1--;
            s.erase(itr1);
        }
        cnt++;
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
