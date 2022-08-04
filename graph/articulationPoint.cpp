#include<bits/stdc++.h>
using namespace std;
#define v vector<int>
#define vv vector<vector<int>>
int cnt=0;
int timme=0;
void dfs(vv &graph,v &parent,v &visited,v &discovery,v &low, vector<int>& aritculation,int src){
    visited[src]=1;
    timme++;
    discovery[src]=low[src]=timme;
    int count=0;
    for(auto it:graph[src]){
        if(parent[src]==it){
            continue;
        }else if(visited[it]){
            low[src]=min(discovery[it],low[src]);
        }else{
            parent[it]=src;
            count++;
            dfs(graph,parent,visited,discovery,low,aritculation,it);
            low[src]=min(low[src],low[it]);
            if(parent[src]==-1){
                if(count>=2){
                    aritculation[src]=1;
                }
            }
            else if(low[it]>=discovery[src]){
                aritculation[src]=1;
            }
        }
    }
    
}




int main(){
    int ve,e;
    cin>>ve>>e;
    vector<vector<int>>graph(ve);
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        x=x-1;
        y=y-1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
   v parent(ve);
   parent[0]=-1;
   v visited(ve,0);
   v discovery(ve,0);
   v low(ve,0);
   vector<int> aritculation(ve,0);
   dfs(graph,parent,visited,discovery,low,aritculation,0); 
   for(int i=0;i<ve;i++){
       if(aritculation[i]==1)cnt++;
   }
   cout<<cnt<<endl;
  

    
    
}