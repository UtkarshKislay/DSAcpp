
int minimum(vector<int>&num,int x,int n,vector<vector<int>>&dp){
    if( x==0){
        return 0;
    }
    if(n<0 || x<0){
        return 1e9;
    }
    if(dp[n][x]!=-1){
        return dp[n][x];
    }
    int take=1e9;
    if(x-num[n]>=0){
           take=1+minimum(num,x-num[n],n,dp);
    }
 
   int ntake=minimum(num,x,n-1,dp);
    
    return dp[n][x]= min(take,ntake);
}

int minimumElements(vector<int> &num, int x)
{ 
    int n=num.size();
 
    vector<vector<int>>dp(n,vector<int>(x+1,0));

    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            int take=1e9;
            if(j-num[i]>=0){
                take=1+dp[i][j-num[i]];
            }
            int notake=1e9;
            if(i-1>=0){
                notake=dp[i-1][j];
            }
             dp[i][j]=min(take,notake);
        }
    }
    int ans=dp[n-1][x];
    if(ans>=1e9){
        return -1;
    }
   return ans;

  
}