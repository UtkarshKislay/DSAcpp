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

class Fenwick2D{
  vector<vector<int>>fenwick;
  int col,row;
  public:
  Fenwick2D(vector<vector<int>>input,int row,int col){
      this->row=row+1;
      this->col=col+1;
      fenwick.resize(row+1);
      for(int i=0;i<=col;i++){
          fenwick[i].resize(col+1);
      }
      
      for(int i=1;i<=row;i++){
          for(int j=1;j<=col;j++){
              update(i,j,input[i][j]);
            //   cout<<fenwick[i][j]<<" ";
          }
        //   cout<<endl;
      }
      
  }
  
  void update(int x,int y,int val){
      int xdas=x;
      while(xdas<row){
          int ydas=y;
          while(ydas<col){
              fenwick[xdas][ydas]+=val;
              ydas+=(ydas&-ydas);
          }
          xdas+=(xdas&-xdas);
      }
  }
  
  int query(int x1,int y1,int x2,int y2){
      int inc1=prefixSum(x2,y2);
      int exc1=prefixSum(x1-1,y2);
      int exc2=prefixSum(x2,y1-1);
      int inc2=prefixSum(x1-1,y1-1);
      
      return inc1+inc2-exc1-exc2;
  }
  
  int prefixSum(int x,int y){
      int sum=0;
      int xdas=x;
      while(xdas>0){
          int ydas=y;
          while(ydas>0){
              sum+=fenwick[xdas][ydas];
              ydas-=(ydas&-ydas);
          }
          xdas-=(xdas&-xdas);
      }
      return sum;
  }
  
  
  
    
};

int main() {
    
    int n,m;cin>>n>>m;
    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    Fenwick2D f2d(arr,n,m);
    
    int q;cin>>q;
    for(int i=0;i<q;i++){
        char ch;cin>>ch;
        if(ch=='q'){
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            cout<<f2d.query(x1,y1,x2,y2)<<endl;
        }else{
            int x1,x2,val;cin>>x1>>x2>>val;
            f2d.update(x1,x2,val);
        }
    }
    
    
    
}


void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}