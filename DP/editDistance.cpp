#include<algorithm>

int distance(string &str1,string &str2,int n,int m,vector<vector<int>>&dp){
//     if(n==0 || m==0){
//         return max(n,m);
//     }
    
    if(n<0)return m+1;
    if(m<0)return n+1;
    
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    
    if(str1[n]==str2[m]){
        return dp[n][m]= distance(str1,str2,n-1,m-1,dp);
    }
    
        int ans1=distance(str1,str2,n-1,m,dp)+1;
   
        int ans2=distance(str1,str2,n,m-1,dp)+1;
  
        int ans3=distance(str1,str2,n-1,m-1,dp)+1;
        
        return dp[n][m]= min(ans1,min(ans2,ans3));
    
}