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

int coinChange(int n,vector<int>&arr,vector<vector<int>>&dp,int d,int i,string s){
   if(n<0 || i==d)return 0;
   if(n==0){
   	cout<<s<<end_l;
   	return 1;
   }

  if(dp[i][n]!=-1){
  	return dp[i][n];
  }

	int first=coinChange(n-arr[i],arr,dp,d,i,s+" "+to_string(arr[i]));
	int second=coinChange(n,arr,dp,d,i+1,s);

	int ans=first+second;
	dp[i][n]=ans;
	return ans;
}


int main(int argc, char const *argv[])
{   
    // boost  
       in_itCode();
  
       int n;cin>>n;
       int d;cin>>d;
       vector<int>arr(d);
       for(int i=0;i<d;i++)cin>>arr[i];
       vector<vector<int>>dp(d+1,vector<int>(n+1,-1));
   int ans=coinChange(n,arr,dp,d,0,"");
   cout<<ans<<end_l;


  


      
	return 0;
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}