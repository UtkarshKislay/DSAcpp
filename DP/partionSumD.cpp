int mod=1e9+7;

int countPartitions(int n, int tar,vector<vector<int>>&dp, vector<int> &arr) {
   if(n==0){
       if(tar==0 && arr[n]==0){
           return 2;
       }
       if(tar==0|| tar==arr[0])return 1;
       return 0;
   }
    
    if(tar<0 || n<0)return 0;
    if(dp[n][tar]!=-1)return dp[n][tar];
    int ans1=countPartitions(n-1,tar-arr[n],dp,arr);
    int ans2=countPartitions(n-1,tar,dp,arr);
    
    return dp[n][tar]= (ans1+ans2)%mod;
    
}

int countPartitions(int n, int d, vector<int> &arr) {
   int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
  
    if((sum-d)<0 || (sum-d)%2!=0)return 0;
    int tar=(sum-d)/2;
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    if(arr[0]==0){
        dp[0][0]=2;
    }else{
        dp[0][0]=1;
    }
    
    if(arr[0]!=0 && arr[0]<=tar)dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=tar;j++){
            dp[i][j]=dp[i-1][j];
            if(j-arr[i]>=0){
                dp[i][j]=(dp[i-1][j-arr[i]]+dp[i][j])%mod;
            }
        }
    }
    return dp[n-1][tar];
//     return countPartitions(n-1,(sum-d)/2,dp,arr);
}