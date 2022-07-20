#include<vector>
//**************************************************************************************
#define ll long long int
int maxpro(vector<int>&price,int n,int i,int cap,int buy,vector<vector<vector<ll>>>&dp){
    if(cap==0 || i==n){
        return 0;
    }
    if(dp[i][cap][buy]!=-1){
        return dp[i][cap][buy];
    }
    if(buy){
        return dp[i][cap][1]= max(-price[i]+maxpro(price,n,i+1,cap,0,dp),maxpro(price,n,i+1,cap,1,dp));
    }else{
        return dp[i][cap][0]= max(price[i]+maxpro(price,n,i+1,cap-1,1,dp),maxpro(price,n,i+1,cap,0,dp));
    }
}

int maxProfit(vector<int>& price, int n)
{  
//     vector<vector<int>>dp(n,vector<int>(2,-1));
    vector<vector<ll>>dp(2,vector<ll>(3,0)),prev(2,vector<ll>(3,0));
 
    for(int i=n-1;i>=0;i--){
       for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=2;cap++){
            if(buy){
                dp[buy][cap]=max(-price[i]+prev[0][cap],prev[1][cap]);
            }else{
                dp[buy][cap]=max(price[i]+prev[1][cap-1],prev[0][cap]);
            }
        }
    }
        prev=dp;
    }
    return prev[1][2];
//    return maxpro(prices,n,0,2,1,dp);
}


//***************************************************************************************
   // Another Code:
#include<vector>
int maxProfit1(vector<int>&price,int n ,int i, int ts,vector<vector<int>>&dp){
    if(ts>=4 || i==n){
        return 0;
    }
    if(dp[i][ts]!=-1){
        return dp[i][ts];
    }
    if(ts%2==0){
        return dp[i][ts]= max(-price[i]+maxProfit1(price,n,i+1,ts+1,dp),maxProfit1(price,n,i+1,ts,dp));
    }else{
        return dp[i][ts]=max(price[i]+maxProfit1(price,n,i+1,ts+1,dp),maxProfit1(price,n,i+1,ts,dp));
    }
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return maxProfit1(prices,n,0,0,dp);
}

//********************************************************************************************
int maxProfit(vector<int>& price, int n)
{
    vector<int>dp(5,0),prev(5,0);
    for(int i=n-1;i>=0;i--){
        for(int ts=0;ts<4;ts++){
            if(ts%2==0){
                dp[ts]=max(-price[i]+prev[ts+1],prev[ts]);
            }else{
                dp[ts]=max(price[i]+prev[ts+1],prev[ts]);
            }
        }
        prev=dp;
    }
    return dp[0];
//     return maxProfit1(prices,n,0,0,dp);
}