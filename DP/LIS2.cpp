int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
           if(arr[j]<arr[i]){
               dp[i]=max(dp[i],1+dp[j]);
           }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}

int lis(int arr[],int n,vector<vector<int>>&dp,int idx){

    if(n<0)return 0;
    
    int ans1=-1e8;
    if(dp[n][idx+1]!=-1){
        return dp[n][idx+1];
    }
    if (idx==-1 || arr[idx]>arr[n]){
        ans1= 1+lis(arr,n-1,dp,n);
    }
    int ans2=lis(arr,n-1,dp,idx);
    return dp[n][idx+1]= max(ans1,ans2);
    
}


//******************************************************************************
//                            NlogN
#include<vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp;
    dp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>dp.back()){
            dp.push_back(arr[i]);
        }else{
            int idx=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
            dp[idx]=arr[i];
        }
    }
    return dp.size();
}

//******************************************************************************
//                          PRINT LIS
#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    int n=arr.size();
    vector<int>dp(n,1),hash(n,0);
    int maxi=1;
    int lidx=0;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && 1+dp[j]>dp[i]) {
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lidx=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lidx]);
    while(hash[lidx]!=lidx){
        lidx=hash[lidx];
        temp.push_back(arr[lidx]);
    }
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    return temp;
}