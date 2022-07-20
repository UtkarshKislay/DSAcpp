int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>>&dp) 
{
    if(n==1){
        if(maxWeight-weight[0]>=0){
            return value[0];
        }
            return 0; 
    }
    if(dp[n-1][maxWeight]!=-1){
        return dp[n-1][maxWeight];
    }
    
    int take1=0;
    if(maxWeight-weight[n-1]>=0){
         take1=knapsack1(weight,value,n-1,maxWeight-weight[n-1],dp)+value[n-1];
    }
   
    int ntake2=knapsack1(weight,value,n-1,maxWeight,dp);
    
    return dp[n-1][maxWeight]= max(take1,ntake2);
    
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
//     for(int i=0;i<n;i++){
        dp[0][0]=0;
//     }
    for(int i=1;i<=maxWeight;i++){
        if(i-weight[0]>=0){
            dp[0][i]=value[0];
        }else{
            dp[0][i]=dp[0][i-1];
        }
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(j-weight[i]>=0){
                dp[i][j]=dp[i-1][j-weight[i]]+value[i];
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }
     
    return dp[n-1][maxWeight];
// 	return knapsack1(weight,value,n,maxWeight,dp);
}


//optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<int>dp(maxWeight+1,0);

        dp[0]=0;

    for(int i=1;i<=maxWeight;i++){
        if(i-weight[0]>=0){
            dp[i]=value[0];
        }else{
            dp[i]=dp[i-1];
        }
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=maxWeight;j>=0;j--){
            int take=0;
            if(j-weight[i]>=0){
                take=dp[j-weight[i]]+value[i];
            }
            dp[j]=max(dp[j],take);
        }
    }
     
    return dp[maxWeight];
// 	return knapsack1(weight,value,n,maxWeight,dp);
}









