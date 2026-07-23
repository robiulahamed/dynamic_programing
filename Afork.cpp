//https://atcoder.jp/contests/dp/tasks/dp_a




#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18;
int n;
 vector<int>h(1000005);
 // dp create
 vector<int>dp(1000005);

#define forn(i, n) for (int i = 0; i < int(n); i++)


int solve(int idx){
    //base case
    if(idx == n-1) return 0;

    //check dp value
    
        if(dp[idx] != -1){
            return dp[idx];
        }
    

    //function body

    int res1 = abs(h[idx]-h[idx+1]) +solve(idx+1); //first step

    int res2 = INF;
    if(idx+2<n){
        res2 = abs(h[idx]-h[idx+2]) +solve(idx+2);//2nd step
    }
    int result = min(res1,res2); // find minimum cost
    //update dp value
    dp[idx] = result;
    return result;
}
int main(){
    fastio;
    cin>>n;
    
    int i=0;
    forn(i,n)cin>>h[i];
    i=0;
    forn(i,n)dp[i]=-1;

    int ans = solve(0);
    cout<<ans<<endl;

    return 0;
}

