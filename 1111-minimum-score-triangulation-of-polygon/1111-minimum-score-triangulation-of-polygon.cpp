class Solution {
public:
    int solve(vector<int>& arr,int i,int j,vector<vector<int>>&dp){
        int ans=INT_MAX;
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1;k<j;k++){
            ans=min(ans,arr[i]*arr[j]*arr[k]+solve(arr,i,k,dp)+solve(arr,k,j,dp));
        }
        dp[i][j]=ans;
        return  dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};