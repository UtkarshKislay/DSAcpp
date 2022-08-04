#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------------
#define ll                    long long int
#define endl                  "\n"
#define loop(i,a,b)           for(int i=a;i<b;i++)
#define boost                 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vector1D(arr,n)       vector<int>arr(n)
#define vector2D(arr,n,m,val) vector<vector<int>>arr(n,vector<int>(m,val))
#define v                     vector<int>
#define vv                    vector<vector<int>>
#define pb                    push_back
#define all(arr)              arr.begin(),arr.end()
#define makep                 make_pair<int,int>
#define vectorPair            vector<pair<int,int>> 
#define inf INT_MAX
#define ninf INT_MIN
const int M=1000000007;
void print(vector<int>&arr){int n=arr.size();for(int i=0;i<n;i++){cout<<arr[i]<<" ";}}
void print(vector<vector<int>>&arr){
  int n=arr.size();int m=arr[0].size();loop(i,0,n){loop(j,0,m){cout<<arr[i][j]<<" ";}cout<<endl;}
}
//--------------------------------------------------------------------------------------



int main(int argc, char const *argv[])
{   
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   sort(arr.begin(),arr.end());
   int cnt=1;
   for(int i=1;i<n;i++){
      if(arr[i]!=arr[i-1]){
        cnt++;
      }
   }
   cout<<cnt<<endl;

  return 0;
}