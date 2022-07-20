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

int minStir1(int n){
	//Recursion
	if(n==0)return 1;
	if(n<0)return 0;
	return minStir1(n-1)+minStir1(n-2)+minStir1(n-3);
}

int minStir2(int n,vector<int>&dp){
	//DP memoization or memoisation
	if(n==0)return 1;
	if(n<0)return 0;

	if(dp[n]!=-1)return dp[n];
	return dp[n]=minStir2(n-1,dp)+minStir2(n-2,dp)+minStir2(n-3,dp);
}

int minStir3(int n,vector<int>&dp){
	//DP Tabulation 
	dp[0]=1;
	for(int i=1;i<=n;i++){
       dp[i]=dp[i-1];
       if(i-2>=0)dp[i]+=dp[i-2];
       if(i-3>=0)dp[i]+=dp[i-3];
	}

	return dp[n];
}

int minStir4(int n){
	//optimized
	int a=1,b=0,c=0,d=0;
	for(int i=1;i<=n;i++){
		int d=a+b+c;
		c=b;
		b=a;
		a=d;
	}
	return a;
}


int main(int argc, char const *argv[])
{   
    // boost  
       in_itCode();
    //  int t;cin>>t;
   //   while(t--){

  //     } 

       int n;cin>>n;
       vector<int>dp(n+1,-1);
       cout<<minStir4(n)<<endl;

  


      
	return 0;
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}