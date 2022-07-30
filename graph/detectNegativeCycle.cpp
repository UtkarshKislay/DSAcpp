#include<bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n,vector<vector<int>>&edges)
{
     vector<int>ans(n+1,INT_MAX);
     ans[0]=0;
     for(int i=1;i<=n-1;i++){
         for(int j=0;j<edges.size();j++){
             int u=ans[edges[j][0]];
             int v=ans[edges[j][1]];
             int cost=edges[j][2];
             if(u==INT_MAX)continue;
             if(u+cost<v){
                 ans[edges[j][1]]=u+cost;
             }
         }
     }
     for(int j=0;j<edges.size();j++){
          int u=ans[edges[j][0]];
             int v=ans[edges[j][1]];
             int cost=edges[j][2];
             
             if(u+cost<v){
                 return 1;
             }
     }
     return 0;
}

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(3));
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=z;
        
    }
    
    cout<<isNegativeWeightCycle(n, edges);
}