//*****************************************************************************************
//          DFS

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<int>adj[],vector<bool>&vis,int start,int parent){
   
       vis[start]=true;
       for(auto it:adj[start]){
           if(!vis[it]){
               if(isCycle(adj,vis,it,start)) return true;
           }else if(it!=parent)return true;
       }
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V+1,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
               bool ans=isCycle(adj,vis,i,-1);
                if(ans)return true;
            }
        }
        return false;
    }
};

//**********************************************************************************************
//      
class Solution {                           
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        queue<pair<int,int>>q;
        vector<int>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                q.push({i,-1});
                vis[i]=true;
                while(!q.empty()){
                    auto cur=q.front();
                    q.pop();
                    for(auto it:adj[cur.first]){
                        if(!vis[it]){
                            vis[it]=true;
                            q.push({it,cur.first});
                        }else {
                            if(vis[it] && cur.second!=it){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
//******************************************************************************