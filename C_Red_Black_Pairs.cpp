#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18;

void solve();

#define forn(i, n) for (int i = 0; i < int(n); i++)
int main(){
    fastio;
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

void solve(){
    int n;cin>>n;
    vector<int>dp(n+1,INF);
    string s[2];
    cin>>s[0]>>s[1];
    dp[0]=0;
    for(int i=0; i<n;  i++){
        int cv = (s[0][i] !=  s[1][i]);
        dp[i+1] = min(dp[i+1],dp[i]+cv);

        int ch = 0;
        if(s[0][i] != s[0][i+1])ch++;
        if(s[1][i] != s[1][i+1]) ch++;

        if(i+1<n){
            dp[i+2]= min(dp[i+2],dp[i]+ch);
        }
    }
    cout<<dp[n]<<endl;
}