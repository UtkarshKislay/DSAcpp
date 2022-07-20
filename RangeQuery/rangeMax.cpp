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



int main() {
     in_itCode();
   int n,q,m;cin>>n>>q>>m;
   vector<pair<int,int>>v;
   for(int i=0;i<q;i++){
       int a,b;cin>>a>>b;
       v.push_back({a-1,b-1});
   }
   vector<int>prefix(n,0);
   for(int i=0;i<q;i++){
       prefix[v[i].first]+=1;
       if(v[i].second<n-1){
           prefix[v[i].second+1]+=-1;
       }
   }
   vector<int>ans(n);
   for(int i=0;i<n;i++){
      if(i==0){
          ans[i]=prefix[i];
      }else{
          ans[i]=prefix[i]+ans[i-1];
      }
   }
//   for(int i=0;i<n;i++)cout<<ans[i]<<" ";
//   cout<<endl;
  vector<int>pCountm(n,0),pCountn(n,0);
  for(int i=0;i<n;i++){
      if(i==0){
          if(ans[i]==m)pCountm[i]=1;
          else if(ans[i]==m+1)pCountn[i]=1;
          continue;
      }
      if(ans[i]==m){
            pCountm[i]=1+pCountm[i-1];
            pCountn[i]=pCountn[i-1];
      }else if(ans[i]==m+1){
          pCountm[i]=pCountm[i-1];
          pCountn[i]=1+pCountn[i-1];
      }else{
            pCountn[i]=pCountn[i-1];
             pCountm[i]=pCountm[i-1];
      }
  }
//   for(int i=0;i<n;i++)cout<<pCountm[i]<<" ";
//   cout<<endl;
//   for(int i=0;i<n;i++)cout<<pCountn[i]<<" ";
//   cout<<endl;
//   cout<<pCountm[n-1]<<" "<<pCountn[n-1]<<endl;
  int ansMax=0;
  int cnt=pCountm[n-1];
  for(int i=0;i<q;i++){
      int a=v[i].first;
      int b=v[i].second;
      
      if(a-1<0){
            int loss=pCountm[b];
           int profit=pCountn[b];
           ansMax=max(ansMax,cnt-loss+profit);
      }else{
            int loss=pCountm[b]-pCountm[a-1];
           int profit=pCountn[b]-pCountn[a-1];
            ansMax=max(ansMax,cnt-loss+profit);
      }
     
     
    
  }
  
       cout<<ansMax<<endl;

 
}
void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}