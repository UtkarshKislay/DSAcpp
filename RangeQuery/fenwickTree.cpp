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


class FenwickTree{
    // vector<int>fenwick;
    public:
    int *fenwick;
    int size;
    // public:
    FenwickTree(vector<int>arr,int n ){
        this->size=n+1;
        fenwick=new int[n+1];
        for(int i=0;i<n+1;i++){
            fenwick[i]=0;
        }
        // fenwick.reserve(n+1);
        for(int i=1;i<=n;i++){
            update(i,arr[i]);
        }
        // for(int i=0;i<=n;i++){
        //     cout<<fenwick[i]<<" ";
        // }
        // cout<<endl;
        
    }
    int query(int l,int r){
        if(l-1>0){
           return prefixSum(r)-prefixSum(l-1); 
        }
        return prefixSum(r);
    }
    int prefixSum(int idx){
        int sum=0;
        while(idx>0){
            sum+=fenwick[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
    void update(int idx,int del){
        while(idx<size){
            fenwick[idx]+=del;
            idx+=(idx&-idx);
        }
    }
    
    
    
};


int main(int argc, char const *argv[])
{   
    // boost  
    //   in_itCode();
    int n;cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    FenwickTree ft(arr,n);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        char ch;cin>>ch;
        int a,b;cin>>a>>b;
        if(ch=='q'){
            cout<<ft.query(a,b)<<endl;
        }else{
            ft.update(a,b);
        }
    }
    
    
    


  


      
	return 0;
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}