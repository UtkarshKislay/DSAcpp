/*
If you can't conquer yourself, then forget to conquer the world !!
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
// void in_itCode();
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
//*********************************************************************
// Normal DSU 
// O(N)
int find(int x,vector<int>&arr){
  if(arr[x]==x){
    return x;
  }
  return find(arr[x],arr);
}

void unionfind(int x,int y,vector<int>&arr){
    int lx=find(x,arr);
    int ly=find(y,arr);

    if(lx!=ly){
        arr[lx]=ly;
    }
}

//*********************************************************************
// Path Compressed and union by rank
// O(logN)
// combined O(1)
int findPathCompression(int x,vector<int>&arr){
  if(arr[x]==x){
    return x;
  }
  int temp= findPathCompression(arr[x],arr); 
  arr[x]=temp;
  return temp;
}

void unionfindByRank(int x,int y,vector<int>&arr,vector<int>&rank){
    int lx=findPathCompression(x,arr);
    int ly=findPathCompression(y,arr);

    if(lx!=ly){
       if(rank[lx]>rank[ly]){
        arr[ly]=lx;
       }else if(rank[ly]>rank[lx]){
        arr[lx]=ly;
       }else{
        arr[lx]=ly;
        rank[lx]++;
       }
    }
}

//*********************************************************************


int main(int argc, char const *argv[])
{   
    int n;cin>>n;
    int m;cin>>m;
    vector<int>arr(n);
    
  return 0;
}




