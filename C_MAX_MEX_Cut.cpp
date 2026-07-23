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
    string s[2];
    cin>>s[0]>>s[1];
    vector<int>dp(n,-1);
    for(int i=0; i<n-1; i++){
        if(s[0][i] != s[1][i]) dp[i]=2;
        else if(s[0][i] == s[1][i]  && s[1][i]=='1'){
            if(s[0][i+1]=='0' || s[1][i+1]=='0'){
                dp[i+1] = 2;
                i++;
            }
            else{
                dp[i]=0;
            }
        }
        else if(s[0][i] == s[1][i]  && s[1][i]=='0'){
            if(s[0][i+1]=='1' && s[1][i+1] == '1'){
                dp[i+1]=2;
                i++;
            }
            else{
                dp[i]=1;
            }
        }
    }

    if(dp[n-1]==-1){
        if(s[0][n-1] ==  s[1][n-1] &&  s[0][n-1]=='0') dp[n-1]=1;
        else if(s[0][n-1] ==  s[1][n-1] &&  s[0][n-1]=='1') dp[n-1]=0;
        else dp[n-1]=2;
    }
    ll sum = 0;
    for(int i=0; i<n ;  i++){
        if(dp[i]!=-1) sum+=dp[i];
    }
    cout<<sum<<endl;
}