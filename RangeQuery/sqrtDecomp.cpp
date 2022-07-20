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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int len=ceil(sqrt(n));
    vector<int>temp(len,INT_MAX);
    for(int i=0;i<n;i++){
        temp[i/len]=min(temp[i/len],v[i]);
    }
    for(int i=0;i<len;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl<<endl;
    int q;cin>>q;
    vector<vector<int>>ans;
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        ans.push_back({a,b});
    }
    for(int i=0;i<q;i++){
        int a=ans[i][0];
        int b=ans[i][1];
        cout<<a<<" "<<b<<endl;
        int minn=INT_MAX;
        while(a<=b){
            if(a%len==0 && a+len-1<=b){
                minn=min(minn,temp[a/len]);
                a+=len;
            }else{
                minn=min(minn,v[a]);
                a++;
            }
        }
        cout<<minn<<endl;
    }
    
   
    // for(int i=0;i<len;i++){
    //     cout<<temp[i]<<" ";
    // }
    
    
  


 
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}