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


int main(int argc, char const *argv[])
{   
    // boost  
      in_itCode();
    //  int t;cin>>t;
   //   while(t--){

  //     } 
  
  int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int len=ceil(sqrt(n));
    vector<int>temp(len,0);
    for(int i=0;i<n;i++){
        temp[i/len]+=v[i];
    }
    for(int i=0;i<len;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl<<endl;
    int q;cin>>q;
    vector<vector<int>>ans;
    for(int i=0;i<q;i++){
        char ch;cin>>ch;
        int a,b;cin>>a>>b;
        // ans.push_back({a,b});
        int ans=0;
        if(ch=='f'){
            while(a<=b){
                if(a%len==0 && a+len-1<=b){
                    ans+=temp[a/len];
                    a+=len;
                }else{
                    ans+=v[a];
                    a++;
                }
            }
            cout<<ans<<endl;
        }else{
            v[a]+=b;
            temp[a/len]+=b;
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