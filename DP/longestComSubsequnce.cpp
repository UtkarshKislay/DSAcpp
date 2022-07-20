#include<vector>
int lcs(string s,string t,int n,int m,vector<vector<int>>&dp){
    if(n<0 || m<0){
        return 0;
    }
    int ans1=0;
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s[n]==t[m]){
        ans1=lcs(s,t,n-1,m-1,dp)+1;
    }
    int ans2=max(lcs(s,t,n-1,m,dp),lcs(s,t,n,m-1,dp));
    return dp[n][m]= max(ans1,ans2);
}

int lcs(string s, string t)
{
	int n=s.size(),m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,0));
     if(t[0]==s[0]){
          dp[0][0]=1;
      }
    for(int i=1;i<m;i++){
       dp[0][i]=dp[0][i-1];
       if(s[0]==t[i]){
           dp[0][i]=1;
       }
    }
    for(int i=1;i<n;i++){
         dp[i][0]=dp[i-1][0];
        if(s[i]==t[0]){
            dp[i][0]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int ans1=0;
            if(s[i]==t[j]){
                ans1=dp[i-1][j-1]+1;
            }
            int ans2=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(ans1,ans2);
        }
    }
    
    return dp[n-1][m-1];
    
//     return lcs(s,t,n-1,m-1,dp);
}

//----------------------------------------------------------------------------------
// optimize;
int lcs(string s, string t)
{
	int n=s.size(),m=t.size();
    vector<int>dp(m,0);
     if(t[0]==s[0]){
          dp[0]=1;
      }
    for(int i=1;i<m;i++){
       dp[i]=dp[i-1];
       if(s[0]==t[i]){
           dp[i]=1;
       }
    }
  
    for(int i=1;i<n;i++){
        vector<int>temp(m,0);
        for(int j=1;j<m;j++){
            int ans1=0;
            if(s[i]==t[j]){
                ans1=dp[j-1]+1;
            }
            int ans2=max(temp[j-1],dp[j]);
            temp[j]=max(ans1,ans2);
        }
        dp=temp;
    }
    
    return dp[m-1];
    
//     return lcs(s,t,n-1,m-1,dp);
}

//------------------------------------------------------------------------------
//       ********** PRINT LCS***********
int lcs(string s, string t)
{
	int n=s.size(),m=t.size();
//     vector<vector<int>>dp(n,vector<int>(m+1,-1));
//     int n=s.size(),m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//      if(t[0]==s[0]){
//           dp[0][0]=1;
//       }
//     for(int i=1;i<m;i++){
//        dp[0][i]=dp[0][i-1];
//        if(s[0]==t[i]){
//            dp[0][i]=1;
//        }
//     }
//     for(int i=1;i<n;i++){
//          dp[i][0]=dp[i-1][0];
//         if(s[i]==t[0]){
//             dp[i][0]=1;
//         }
//     }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans1=0;
            if(s[i-1]==t[j-1]){
                ans1=dp[i-1][j-1]+1;
            }
            int ans2=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(ans1,ans2);
        }
    }
    int len=dp[n][m];
    int i=n,j=m;
    vector<char>str(len);
    int k=len-1;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            str[k]=s[i-1];
            i--;
            j--;
            k--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
        if(i<0 || j<0){
            break;
        }
    }
    for(int i=0;i<len;i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    return len;
    
    
}
