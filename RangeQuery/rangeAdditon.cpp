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

vector<int>modify(int n,vector<vector<int>>&arr){
    vector<int>ans(n,0);
    for(int i=0;i<arr.size();i++){
        ans[arr[i][0]]+=arr[i][2];
        if(arr[i][1]<n-1){
            ans[arr[i][1]+1]+=-arr[i][2];
        }
    }
    vector<int>final(n,0);
    for(int i=0;i<n;i++){
        if(i==0)final[i]=ans[i];
        else final[i]=ans[i]+final[i-1];
    }
    return final;
    
}

int main() {
     in_itCode();
    int n;cin>>n;
    int k;cin>>k;
    vector<vector<int>>arr;
    for(int i=0;i<k;i++){
        int a,b,c;cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    vector<int>ans=modify(n,arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
 
}
void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}