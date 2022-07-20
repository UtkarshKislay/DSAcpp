#include<vector>
#define ll long long int
long maxProf(long *values,int n,int buy,int i,vector<vector<ll>>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    ll profit=0;
    if(buy){
       ll ans1=-values[i]+maxProf(values,n,0,i+1,dp);
       ll ans2=maxProf(values,n,1,i+1,dp);
        profit= max(ans1,ans2);
    }else{
        ll ans1=values[i]+maxProf(values,n,1,i+1,dp);
        ll ans2=maxProf(values,n,0,i+1,dp);
        profit= max(ans1,ans2);
    }
    return dp[i][buy]=profit;
}

long getMaximumProfit(long *values, int n){
    if(n==0 || n==1)return 0;
    ll currBuy=0,currNotBuy=0,prevBuy=0,prevNotBuy=0;
    int buy=0;
    
    for(int i=n-1;i>=0;i--){
        currNotBuy=max(values[i]+prevBuy,prevNotBuy);
        currBuy=max(-values[i]+prevNotBuy,prevBuy);
           prevBuy=currBuy;
        prevNotBuy=currNotBuy;
        }
     
    
    return currBuy;
}
