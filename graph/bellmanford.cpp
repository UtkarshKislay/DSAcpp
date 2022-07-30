#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(3));
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        edges[i][0]=x-1;
        edges[i][1]=y-1;
        edges[i][2]=z;
        
    }

    vector<int>ans(n+1,INT_MAX);
    ans[0]=0;
    for(int it=0;it<n-1;it++){ //for m-1 iteration
        for(int i=0;i<m;i++){
            
            if(ans[edges[i][0]]+edges[i][2]<ans[edges[i][1]]){ //path[u]+wt<path[v] =>
                ans[edges[i][1]]=ans[edges[i][0]]+edges[i][2];// path[v]=path[u]+wt
            }
        }
    }

    for(int i=1;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}       