/*

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment.
It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent 
in such a way that the total cost of the assignment is minimized.
int costMatrix[N][N] =
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

*/
#include<bits/stdc++.h>
using namespace std;
 
const int m = 1e9 + 7;

int dp[21][(1<<21)]; //can run only for no less than 21

int solve(int i,vector<vector<int>> &cost,int mask,int n){
    
    //base case
    if(i == n){//all jobs has been assigned
        return 0;
    }

    if(dp[i][mask] != -1){
        return dp[i][mask];
    }

    int ans = INT_MAX;

    for(int j=0;j<n;j++){
        //assigning jth person the ith job
        //for that first add the cost and
        //then unset the availablity of ith person
        if(mask & (1<<j)){//check is the person is free or not
        
            ans = min( ans , cost[j][i] + solve(i+1,cost,(mask ^ (1<<j)),n));
        
        }
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
        vector<vector<int>> cost(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        int job_no = 0;
        cout<<solve(job_no,cost,(1<<n)-1,n);
    }

    return 0;

}
