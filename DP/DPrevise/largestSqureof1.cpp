#include<bits/stdc++.h>
using namespace std;



int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>>arr(n,vector<int>(m));
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>arr[i][j];
      }
  }

  vector<vector<int>>dp(n,vector<int>(m,0));
  int maxx=0;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          int ans1=0,ans2=0,ans3=0;
          if(arr[i][j]==0)continue;
          if(i-1>=0)ans1=dp[i-1][j];
          if(j-1>=0)ans2=dp[i][j-1];
          if(i-1>=0 && j-1>=0)ans3=dp[i-1][j-1];
          dp[i][j]=min(ans1,min(ans2,ans3))+1;
          maxx=max(dp[i][j],maxx);
      }
  }
  cout<<maxx<<endl;
  

    return 0;
}