



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

bool partition(vector<int>&arr,int n,int target,vector<vector<int>>&dp){
    
    if(target==0){
        return true;
    }
    
    if(n<0 || target<0){
        return false;
    }

    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    bool ans1=partition(arr,n-1,target-arr[n],dp);
    bool ans2=partition(arr,n-1,target,dp);
    
    return dp[n][target]=ans1||ans2;
    
}

void recursive(vector<int>&arr,int n){
    int su=0;
    for(int i=0;i<n;i++){
        su+=arr[i];
    }
    if(su&1){
        cout<<"False"<<end_l;
        return;
    }
    int target=su/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<boolans(partition(arr,n-1,target,dp))<<end_l;
}

// void dynamic(vector<int>&arr,int n){
//      int sum1=0,sum2=0;
//     int su=0;
//     for(int i=0;i<n;i++){
//         su+=arr[i];
//     }
//     vector<vector<int>>dp(su/2+1,vector<int>(su/2+1,0));
    



// }

// void spaceOptimized(){
  
// }

void solve(){

/*
   You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition
   the given array into two subsets such that the sum of elements in both subsets is equal.
   For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned 
   [2, 3, 5], and [3, 3, 4] with equal sum 10.
*/

  int n;cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  

  recursive(arr,n);
//   dynamic(arr,n);
//   spaceOptimized(arr,n);

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

