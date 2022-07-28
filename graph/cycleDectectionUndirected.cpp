//**********************************************************************************************
#include<bits/stdc++.h>
class Solution {
  public:
  
  bool dfs(int V,vector<int>adj[],vector<bool>&vis,vector<bool>&dfsVis,int src){
     
      vis[src]=true;
      dfsVis[src]=true;
      for(auto it:adj[src]){
          if(!vis[it]){
              if(dfs(V,adj,vis,dfsVis,it))return true;
          }else if(dfsVis[it]){
              return true;
          }
      }
      dfsVis[src]=false;
      return false;
  }
   
    bool isCyclic(int V, vector<int> adj[]) {
      vector<bool>vis(V,false);
      vector<bool>dfsVis(V,false);
     
      for(int i=0;i<V;i++){
          if(!vis[i]){
             if(dfs(V,adj,vis,dfsVis,i)){
              return true;
            } 
          }
          
      }
      return false;
     
    }
};

//***********************************************************************************************

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>dep(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                dep[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(dep[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int cr=q.front();
            q.pop();
          cnt++;
            for(auto it:adj[cr]){
                dep[it]--;
                if(dep[it]==0){
                    q.push(it);
                }
            }
            
        }
        if(cnt==V)return false;
        return true;
    }
};



