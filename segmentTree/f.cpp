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

class SegmentTree{
 public:  
 vector<int>tree;
 vector<int>arr;

  SegmentTree(int n,vector<int>&ar){
     tree.resize(4*n+1);
  
     arr=ar;
     build(1,0,n-1);
  }
  void build(int node,int start,int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    tree[node]=0;
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
  }
  
  void update(int l,int r,int val){
    return update(1,0,arr.size()-1,l,r,val);
  }
  void update(int node,int start,int end,int l,int r,int val){
    if(start>r || end<l){
        return ;
    }
    if(start>=l && end<=r){
        tree[node]+=val;
        return;
    }
    if(start==end){
        tree[node]+=val;
    }
     
     int mid=(start+end)/2;
     update(node*2,start,mid,l,r,val);
     update(node*2+1,mid+1,end,l,r,val);
    
  }

  void printTree(){
    int n=arr.size();
    int node=1;
    queue<int>q;
    q.push(node);
    q.push(-1);
    while(!q.empty()){
        int val=q.front();
        q.pop();
        if(val==-1){
            cout<<endl;
            if(q.size()>0){
                q.push(-1);
            }
            continue;
        }
        cout<<tree[val]<<" ";
        if(val*2<=4*n){
            q.push(val*2);
        }
        if(val*2+1<=4*n){
            q.push(val*2+1);
        }
    }
  }


  int query(int pos){
    return query(1,0,arr.size()-1,pos);
  }
  int query(int node,int start,int end,int pos){
    if(start>pos || end<pos){
        return 0;
    }
    int ans=0;
     if(start==end){
        ans=tree[node];
        return ans;
    }
    int mid=(start+end)/2;
    ans+=tree[node];
    if(pos>=start && pos<=mid){
      ans+=query(node*2,start,mid,pos);
    }else{
      ans+=query(node*2+1,mid+1,end,pos);
    }
    return ans;
  }
  

};

int main(int argc, char const *argv[])
{   
    int n;cin>>n;
     vector<int>arr(n);
     loop(i,0,n)cin>>arr[i];
     SegmentTree sg(n,arr);

     int q;cin>>q;
     while(q--){
        int t;cin>>t;
        if(t==1){
            int l,r,val;cin>>l>>r>>val;
            sg.update(l,r,val);
        }
        else{
            int pos;cin>>pos;
            cout<<sg.query(pos)<<endl;
        }
       
     }
    

  return 0;
}




