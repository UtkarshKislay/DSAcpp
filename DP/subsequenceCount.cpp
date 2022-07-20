//Recursive code

int subsequence(string &t,string &s,int n,int m,vector<vector<int>>&dp){
   if(m<0){
       return 1;
   }
    if(n<0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(t[n]==s[m]){
        return dp[m][n]= (subsequence(t,s,n-1,m-1,dp)+subsequence(t,s,n-1,m,dp))%mod;
    }
    return dp[m][n]=subsequence(t,s,n-1,m,dp)%mod;
}

 

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>>dp(ls+1,vector<int>(lt+1,-1));
    return subsequence(t,s,lt-1,ls-1,dp);
   
}

//Tabulation

int mod=1e9+7;

int subsequence(string &t,string &s,int n,int m,vector<vector<int>>&dp){
   if(m<0){
       return 1;
   }
    if(n<0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(t[n]==s[m]){
        return dp[m][n]= (subsequence(t,s,n-1,m-1,dp)+subsequence(t,s,n-1,m,dp))%mod;
    }
    return dp[m][n]=subsequence(t,s,n-1,m,dp)%mod;
}

 

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>>dp(ls+1,vector<int>(lt+1,0));
//     if(s[0]==t[0]){
//         dp[0][0]=1;
//     }
   for(int i=0;i<=lt;i++){
       dp[0][i]=1;
   }
    
    for(int i=1;i<=ls;i++){
        for(int j=1;j<=lt;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
            }else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    
    return dp[ls][lt];
//     return subsequence(t,s,lt-1,ls-1,dp);
   
} 

