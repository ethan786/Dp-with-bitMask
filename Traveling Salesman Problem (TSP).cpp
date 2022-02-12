/*
Given a set of cities and distances between every pair of cities,
the problem is to find the shortest possible route that visits
every city exactly once and returns to the starting point. 
{ { 0, 10, 15, 20 },
 { 10, 0, 35, 25 },
 { 15, 35, 0, 30 },
 { 20, 25, 30, 0 } };
*/

#include<bits/stdc++.h>
using namespace std;
 
const int m = 1e9 + 7;

int dp[21][(1<<21)]; //can run only for no less than 21

int solve(int i,vector<vector<int>> &dist,int mask,int n){
    
    //base case
    if(mask == 0){
        return dist[i][1];
    }

    if(dp[i][mask] != -1){
        return dp[i][mask];
    }

    int ans = INT_MAX;

    for(int j=0;j<n;j++){
        if(mask & (1<<j))//is this city visited or not
            ans = min(ans , dist[i][j] + solve(j,dist,(mask ^ (1<<j)),n));
    }
    return dp[i][mask] = ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> dist(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>dist[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,dist,(1<<n)-2,n);
    }

    return 0;

}
