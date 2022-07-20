/*
If you can't conquer yourself, then forget to conquer the world !!
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
void in_itCode();
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>pb_ds;
#define ll long long int
#define end_l "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define vect vector<int>
#define pb push_back
#define makep make_pair<int,int>
#define paivect vector<pair<int,int>> 
#define inf INT_MAX
#define ninf INT_MIN
const int M=1000000007;

string boolans(bool ans){
    if(ans){
       return "True";
    }else{
        return "False";
    }
}

bool subsetSum(int n,int k,vector<int>&arr,int sum,int idx,vector<vector<int>>&dp){
    if(sum==k){
        return true;
    }
    if(idx>=n || sum>k){
        return false;
    }
    if(dp[idx][sum]!=-1){
        return dp[idx][sum];
    }
    bool ans1=false;
    if(arr[idx]+sum<=k){
        ans1=subsetSum(n,k,arr,sum+arr[idx],idx+1,dp);
    }
    bool ans2=subsetSum(n,k,arr,sum,idx+1,dp);
    return dp[idx][sum]=ans1||ans2;
}

void recursive(int n,int k,vector<int>&arr){
    int sum=0;
   vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
   bool ans= subsetSum(n,k,arr,sum,0,dp);
  cout<<boolans(ans)<<end_l;
}

void dynamic(int n,int k,vector<int>&arr){
     vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k){
        dp[0][arr[0]]=true;
    }

    for(int idx=1;idx<n;idx++){
        for(int sum=1;sum<=k;sum++){
            bool ans1=false;
          if(arr[idx]<=sum){
              ans1=dp[idx-1][sum-arr[idx]];
          }
         bool ans2=dp[idx-1][sum];
            dp[idx][sum]=ans1||ans2; 
         }
    }
 cout<<boolans(dp[n-1][k])<<end_l;
 
}

void spaceOptimized(int n,int k,vector<int>&arr){
     vector<bool>dp(k+1,false);
    
     dp[0]=true;
    
    if(arr[0]<=k){
        dp[arr[0]]=true;
    }

    for(int idx=1;idx<n;idx++){
        vector<bool>temp(k+1,false);
        temp[0]=true;
        if(arr[0]<=k){
            temp[arr[0]]=true;
        }
        for(int sum=1;sum<=k;sum++){
            bool ans1=false;
            if(arr[idx]<=sum){
              ans1=dp[sum-arr[idx]];
            }
            bool ans2=dp[sum];

            temp[sum]=ans1||ans2; 
         }
         dp=temp;
    }


 cout<<boolans(dp[k])<<end_l;
}

void solve(){
  int n;cin>>n;
  int k;cin>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  

  recursive(n,k,arr);
  dynamic(n,k,arr);
  spaceOptimized(n,k,arr);

}

int main(int argc, char const *argv[])
{   
    // boost  
      int t;cin>>t;
      while(t--){
         solve();
       } 

  return 0;
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

