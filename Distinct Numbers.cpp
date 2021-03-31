By carrot, contest: CSES Problem Set: Sorting and Searching, problem: (A) Distinct Numbers, Accepted, #, Copy
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int mxN=1e5+2;
void solve(){
    int n;cin>>n;
    set<int>a;
    for(int i=0;i<n;i++) {
        int x;cin>>x;a.insert(x);
    }
    cout<<a.size();
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
